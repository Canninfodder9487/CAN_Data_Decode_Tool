#include <iostream>
#include <UI/CAN_decode_UI.cpp>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <QtCore/QString>
#include <QtCore/QArgument>
#include <QtGui/QValidator>
#include <QtGui/QClipboard>
#include <QtGui/QKeyEvent>
#include <QtCore/QRegularExpression>
#include <QtCore/QMimeData>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonValue>
#include <QtCore/QJsonParseError>
#include <QtCore/QFile>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <memory>
#include <cmath>
#include <icon.cpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

#define CACHE_FILENAME "Setting_Cache.json"

bool isAllHex(const QString &str){
    static QRegularExpression regex("[0-9a-fA-F]");
    for (const QChar &ch:str) if(!regex.match(ch).hasMatch()) return false;
    return true;
}

class Main_Window : public QWidget{
    const unsigned short MAX_DLC = 8;
    Ui_Form ui;
    QDoubleValidator* double_validator = new QDoubleValidator(this);
    QRegExp* hex_reg = new QRegExp("[0-9A-Fa-f]{2}");
    QRegularExpression* data_filter_reg = new QRegularExpression("[ \t,]"); 
    QRegExpValidator* hex_validator = new QRegExpValidator(*hex_reg,this);
    std::vector<QLineEdit*> datas;

    public:
        Main_Window(){
            setWindowIcon(QIcon(":/Icon/decode.ico"));
            ui.setupUi(this);
            
            datas.push_back(ui.Data0);
            datas.push_back(ui.Data1);
            datas.push_back(ui.Data2);
            datas.push_back(ui.Data3);
            datas.push_back(ui.Data4);
            datas.push_back(ui.Data5);
            datas.push_back(ui.Data6);
            datas.push_back(ui.Data7);

            setWindowTitle(QString(std::format("Simple CAN Decode").c_str()));
            ui.Resolution->setValidator(double_validator);
            ui.Offset->setValidator(double_validator);
            ui.Minimum->setValidator(double_validator);
            ui.Maximum->setValidator(double_validator);

            ui.Data0->setValidator(hex_validator);
            ui.Data1->setValidator(hex_validator);
            ui.Data2->setValidator(hex_validator);
            ui.Data3->setValidator(hex_validator);
            ui.Data4->setValidator(hex_validator);
            ui.Data5->setValidator(hex_validator);
            ui.Data6->setValidator(hex_validator);
            ui.Data7->setValidator(hex_validator);

            ui.Data0->installEventFilter(this);
            ui.Data1->installEventFilter(this);
            ui.Data2->installEventFilter(this);
            ui.Data3->installEventFilter(this);
            ui.Data4->installEventFilter(this);
            ui.Data5->installEventFilter(this);
            ui.Data6->installEventFilter(this);

            connect(ui.Data0,&QLineEdit::textChanged,this,&Main_Window::onTextChange);
            connect(ui.Data1,&QLineEdit::textChanged,this,&Main_Window::onTextChange);
            connect(ui.Data2,&QLineEdit::textChanged,this,&Main_Window::onTextChange);
            connect(ui.Data3,&QLineEdit::textChanged,this,&Main_Window::onTextChange);
            connect(ui.Data4,&QLineEdit::textChanged,this,&Main_Window::onTextChange);
            connect(ui.Data5,&QLineEdit::textChanged,this,&Main_Window::onTextChange);
            connect(ui.Data6,&QLineEdit::textChanged,this,&Main_Window::onTextChange);

            connect(ui.Decode_Btn,&QPushButton::clicked,this,&Main_Window::Decode);

            loadJsonCache();
            
        }
        ~Main_Window(){
            delete double_validator;
            delete hex_reg;
            delete data_filter_reg;
            delete hex_validator;
        }
    protected:
        bool eventFilter(QObject* obj, QEvent *event)override{
            if(event->type() == QEvent::KeyPress){
                QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
                if(key_event->matches(QKeySequence::Paste)){
                    pasteData();
                }
                else if(key_event->matches(QKeySequence::Copy)){
                    CopyData();
                }
                else if(key_event->matches(QKeySequence::Delete)){
                    DeleteAllData();
                }
            }
            return obj->eventFilter(obj, event);
        }
        void pasteData(){
            QClipboard *Clipboard = QGuiApplication::clipboard();
            const QMimeData* data = Clipboard->mimeData();
            if(!data->hasText()) return;
            QString t = data->text();
            t = t.remove(*data_filter_reg); // filter space , tab , ','
            if(t.length()> 16){
                QMessageBox::warning(this,"Error","Hex Data too long(>16)");
                return;
            }
            if(!isAllHex(t)){
                QMessageBox::warning(this,"Error","Not valid Hex Data (0-9,A-F,a-f)");
                return;
            }
            for(auto lineedit:datas) lineedit->clear();
            for(int i=0;i<datas.size();i++) datas[i]->setText(t.mid(i*2,2));
            return;
        }
        void CopyData(){
            QString text;
            for(auto lineedit:datas) text.append(lineedit->text() + ' ');
            QApplication::clipboard()->setText(text);
            return;
        }
        void DeleteAllData(){
            for(auto lineedit:datas) lineedit->clear();
            datas[0]->setFocus();
            return;
        }
        void loadJsonCache(){
            if(!QFile::exists(CACHE_FILENAME)) return;
            QFile f(CACHE_FILENAME);
            if(!f.open(QFile::ReadOnly | QFile::Text)) return;
            QByteArray jsonData = f.readAll();
            if(f.isOpen()) f.close();
            QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData));
            if(jsonData.isNull() || !jsonDoc.isObject()) return;

            QJsonObject data = jsonDoc.object();
            // nlohmann::json data = nlohmann::json::parse(f);
            ui.Start_Bit->setValue(data["Start_Bit"].toInt());
            ui.Length->setValue(data["Length"].toInt());
            ui.Byte_order->setCurrentIndex(data["Byte_order"].toInt());
            ui.Value_Type->setCurrentIndex(data["Value_Type"].toInt());
            ui.Offset->setText(data["Offset"].toString());
            ui.Resolution->setText(data["Resolution"].toString());
            ui.Minimum->setText(data["Minimum"].toString());
            ui.Maximum->setText(data["Maximum"].toString());
            return;
        }
        void saveJsonCache(){
            QJsonDocument jsonDoc;
            QJsonObject data;

            data["Start_Bit"] = ui.Start_Bit->value();
            data["Length"] = ui.Length->value();
            data["Byte_order"] = ui.Byte_order->currentIndex();
            data["Value_Type"] = ui.Value_Type->currentIndex();
            data["Offset"] = ui.Offset->text();
            data["Resolution"] = ui.Resolution->text();
            data["Minimum"] = ui.Minimum->text();
            data["Maximum"] = ui.Maximum->text();
            QFile f(CACHE_FILENAME);
            if(!f.open(QIODevice::WriteOnly)) return;
            jsonDoc.setObject(data);
            f.write(jsonDoc.toJson());
            if(f.isOpen()) f.close();
            return;
        }
        void closeEvent(QCloseEvent *event){
            saveJsonCache();
        }
        
    private:
        std::vector<uint> Get_Data(){
            std::vector<uint> data_container(MAX_DLC,0);
            int count = 0;
            for(int i=0;i<datas.size();i++){
                QString data_hex = datas[i]->text();
                if( data_hex.length() && data_hex.length() < 2){
                    QMessageBox::warning(this,"Error","Data is not complete.");
                    return std::vector<uint>();
                }
                if(data_hex.length() == 2){
                    bool ok;
                    uint val = data_hex.toUInt(&ok, 16);
                    if(ok){
                        data_container[i] = val;
                        count++;
                    }
                    else{
                        QMessageBox::warning(this,"Error","Hex translate Error.");
                        return std::vector<uint>();
                    }
                }
            }
            if(!count){
                QMessageBox::warning(this,"Error","No Data Received.");
                return std::vector<uint>();
            }
            return std::vector<uint>(data_container.begin(),data_container.begin()+count);
        }
        bool check_Settings(){
            if(!ui.Length->value()){
                QMessageBox::warning(this,"Error","Length not set.");
                return false;
            }
            /* if(!ui.Start_Bit->value()){
                QMessageBox::warning(this,"Error","Start Bit not set.");
                return false;
             }*/
            if(!ui.Offset->text().size()){
                QMessageBox::warning(this,"Error","Offset not set.");
                return false;
            }
            if(!ui.Resolution->text().size()){
                QMessageBox::warning(this,"Error","Resolution not set.");
                return false;
            }
            return true;
        }
        
        void Decode(){
            std::vector<uint> data_uint = Get_Data();
            if(!data_uint.size()) return;
            if(!check_Settings()) return;
            if(ui.Start_Bit->value() + ui.Length->value() > data_uint.size()*8){
                QMessageBox::warning(this,"Error","Start_Bit + Length is out of index.");
                return;
            }
            uint64_t bits_val = (!ui.Byte_order->currentIndex()) ? 
            getBitsVal_Little(data_uint,ui.Start_Bit->value(),ui.Length->value()) :
            getBitsVal_Big(data_uint,ui.Start_Bit->value(),ui.Length->value());

            
            // Calculate Result
            // bool ok;
            // __float128 Resolution = ui.Resolution->text().toDouble(&ok);
            // if(!ok){
            //     QMessageBox::warning(this,"Error","Decode Error. - Resolution");
            //     return;
            // }
            // __float128 Offset = ui.Offset->text().toDouble(&ok);
            // if(!ok){
            //     QMessageBox::warning(this,"Error","Decode Error. - Offset");
            //     return;
            // }
            boost::multiprecision::cpp_bin_float_100 Resolution(ui.Resolution->text().toStdString());
            boost::multiprecision::cpp_bin_float_100 Offset(ui.Offset->text().toStdString());

            boost::multiprecision::cpp_bin_float_100 result = Offset + (bits_val * Resolution);

            bool min_check = (ui.Minimum->text().length());
            float minimum = ui.Minimum->text().toFloat();
            bool max_check = (ui.Maximum->text().length());
            float maximum = ui.Maximum->text().toFloat();
            
            QString res_str = QString::fromStdString(result.str(9,std::ios_base::fixed));

            QString Error_str;
            if(min_check && max_check && (minimum >= result || result >= maximum)){
                Error_str = QString::fromStdString(std::format("(Error,Value not in range[{}~{}])",minimum,maximum));
            }
            else if(min_check && result < minimum){
                Error_str = QString("(Error,Smaller than Minimum.)");
            }
            else if(max_check && result > maximum){
                Error_str = QString("(Error,Greater than Maximum.)");
            }
            ui.Result->setText(res_str.append(Error_str));
            return;
        }

        uint64_t getBitsVal_Little(const std::vector<uint>&data, int startBit, int length){
            uint64_t result = 0;
            int byteIndex = startBit / 8;
            int bitIndex = startBit % 8;
            int bitsExtracted = 0;

            while (bitsExtracted < length) {
                int bitsToExtract = std::min(8 - bitIndex, length - bitsExtracted);
                uint64_t mask = ((1 << bitsToExtract) - 1) << bitIndex;
                result |= ((data[byteIndex] & mask) >> bitIndex) << bitsExtracted;
                bitsExtracted += bitsToExtract;
                bitIndex = 0;
                byteIndex++;
            }

            return result;
        }
        uint64_t getBitsVal_Big(const std::vector<uint>&data, int startBit, int length){
            uint64_t result = 0;
            int byteIndex = startBit / 8;
            int bitIndex = startBit % 8;
            int bitsExtracted = 0;

            while (bitsExtracted < length) {
                int bitsToExtract = std::min(8 - bitIndex, length - bitsExtracted);
                uint64_t mask = ((1 << bitsToExtract) - 1) << (8 - bitIndex - bitsToExtract);
                result = (result << bitsToExtract) | ((data[byteIndex] & mask) >> (8 - bitIndex - bitsToExtract));
                bitsExtracted += bitsToExtract;
                bitIndex = 0;
                byteIndex++;
            }

            return result;
        }

    private slots:
        void onTextChange(const QString &text){
            QObject* senderLineEdit = sender();
            if (!senderLineEdit) return;

            if(text.length() >= 2){
                auto it = std::find(datas.begin(),datas.end(),senderLineEdit);
                if(it != datas.end()){
                    (*(it+1))->setFocus();
                    (*(it+1))->clear();
                };
            }
            return;
        }
};


int main(int argc, char* argv[]){

    // QCoreApplication::setLibraryPaths(QStringList() << "C:/Qt/5.15.2/mingw81_64/plugins");
    QApplication app(argc,argv);

    Main_Window window = Main_Window();
    window.show();
    
    return app.exec();
}
