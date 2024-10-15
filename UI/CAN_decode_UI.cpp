/********************************************************************************
** Form generated from reading UI file 'CAN_decode_UI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAN_DECODE_UI_H
#define UI_CAN_DECODE_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *Value_Type;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *Start_Bit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *Length;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *Resolution;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *Byte_order;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *Offset;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *Minimum;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLineEdit *Maximum;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *Data0;
    QLineEdit *Data1;
    QLineEdit *Data2;
    QLineEdit *Data3;
    QLineEdit *Data4;
    QLineEdit *Data5;
    QLineEdit *Data6;
    QLineEdit *Data7;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer;
    QPushButton *Decode_Btn;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *Result;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(520, 450);
        Form->setMinimumSize(QSize(500, 450));
        Form->setMaximumSize(QSize(600, 550));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        Form->setFont(font);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(100, 0));
        label_4->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_4);

        Value_Type = new QComboBox(groupBox);
        Value_Type->addItem(QString());
        Value_Type->addItem(QString());
        Value_Type->setObjectName(QString::fromUtf8("Value_Type"));

        horizontalLayout_5->addWidget(Value_Type);


        gridLayout->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label);

        Start_Bit = new QSpinBox(groupBox);
        Start_Bit->setObjectName(QString::fromUtf8("Start_Bit"));
        Start_Bit->setMaximum(63);

        horizontalLayout->addWidget(Start_Bit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_2);

        Length = new QSpinBox(groupBox);
        Length->setObjectName(QString::fromUtf8("Length"));
        Length->setMaximum(64);

        horizontalLayout_2->addWidget(Length);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(100, 0));
        label_8->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(label_8);

        Resolution = new QLineEdit(groupBox);
        Resolution->setObjectName(QString::fromUtf8("Resolution"));

        horizontalLayout_10->addWidget(Resolution);


        gridLayout->addLayout(horizontalLayout_10, 2, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_3);

        Byte_order = new QComboBox(groupBox);
        Byte_order->addItem(QString());
        Byte_order->addItem(QString());
        Byte_order->setObjectName(QString::fromUtf8("Byte_order"));

        horizontalLayout_4->addWidget(Byte_order);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(100, 0));
        label_9->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_11->addWidget(label_9);

        Offset = new QLineEdit(groupBox);
        Offset->setObjectName(QString::fromUtf8("Offset"));

        horizontalLayout_11->addWidget(Offset);


        gridLayout->addLayout(horizontalLayout_11, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Form);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_2);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_12->addWidget(label_10);

        Minimum = new QLineEdit(groupBox_2);
        Minimum->setObjectName(QString::fromUtf8("Minimum"));

        horizontalLayout_12->addWidget(Minimum);


        horizontalLayout_14->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_13->addWidget(label_11);

        Maximum = new QLineEdit(groupBox_2);
        Maximum->setObjectName(QString::fromUtf8("Maximum"));

        horizontalLayout_13->addWidget(Maximum);


        horizontalLayout_14->addLayout(horizontalLayout_13);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Form);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Data0 = new QLineEdit(groupBox_3);
        Data0->setObjectName(QString::fromUtf8("Data0"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Data0->sizePolicy().hasHeightForWidth());
        Data0->setSizePolicy(sizePolicy);
        Data0->setMinimumSize(QSize(30, 0));
        Data0->setMaximumSize(QSize(50, 16777215));
        Data0->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data0);

        Data1 = new QLineEdit(groupBox_3);
        Data1->setObjectName(QString::fromUtf8("Data1"));
        sizePolicy.setHeightForWidth(Data1->sizePolicy().hasHeightForWidth());
        Data1->setSizePolicy(sizePolicy);
        Data1->setMinimumSize(QSize(30, 0));
        Data1->setMaximumSize(QSize(50, 16777215));
        Data1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data1);

        Data2 = new QLineEdit(groupBox_3);
        Data2->setObjectName(QString::fromUtf8("Data2"));
        sizePolicy.setHeightForWidth(Data2->sizePolicy().hasHeightForWidth());
        Data2->setSizePolicy(sizePolicy);
        Data2->setMinimumSize(QSize(30, 0));
        Data2->setMaximumSize(QSize(50, 16777215));
        Data2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data2);

        Data3 = new QLineEdit(groupBox_3);
        Data3->setObjectName(QString::fromUtf8("Data3"));
        sizePolicy.setHeightForWidth(Data3->sizePolicy().hasHeightForWidth());
        Data3->setSizePolicy(sizePolicy);
        Data3->setMinimumSize(QSize(30, 0));
        Data3->setMaximumSize(QSize(50, 16777215));
        Data3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data3);

        Data4 = new QLineEdit(groupBox_3);
        Data4->setObjectName(QString::fromUtf8("Data4"));
        sizePolicy.setHeightForWidth(Data4->sizePolicy().hasHeightForWidth());
        Data4->setSizePolicy(sizePolicy);
        Data4->setMinimumSize(QSize(30, 0));
        Data4->setMaximumSize(QSize(50, 16777215));
        Data4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data4);

        Data5 = new QLineEdit(groupBox_3);
        Data5->setObjectName(QString::fromUtf8("Data5"));
        sizePolicy.setHeightForWidth(Data5->sizePolicy().hasHeightForWidth());
        Data5->setSizePolicy(sizePolicy);
        Data5->setMinimumSize(QSize(30, 0));
        Data5->setMaximumSize(QSize(50, 16777215));
        Data5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data5);

        Data6 = new QLineEdit(groupBox_3);
        Data6->setObjectName(QString::fromUtf8("Data6"));
        sizePolicy.setHeightForWidth(Data6->sizePolicy().hasHeightForWidth());
        Data6->setSizePolicy(sizePolicy);
        Data6->setMinimumSize(QSize(30, 0));
        Data6->setMaximumSize(QSize(50, 16777215));
        Data6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data6);

        Data7 = new QLineEdit(groupBox_3);
        Data7->setObjectName(QString::fromUtf8("Data7"));
        sizePolicy.setHeightForWidth(Data7->sizePolicy().hasHeightForWidth());
        Data7->setSizePolicy(sizePolicy);
        Data7->setMinimumSize(QSize(30, 0));
        Data7->setMaximumSize(QSize(50, 16777215));
        Data7->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(Data7);


        verticalLayout->addWidget(groupBox_3);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer);

        Decode_Btn = new QPushButton(Form);
        Decode_Btn->setObjectName(QString::fromUtf8("Decode_Btn"));

        horizontalLayout_15->addWidget(Decode_Btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_15);

        groupBox_4 = new QGroupBox(Form);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Result = new QLabel(groupBox_4);
        Result->setObjectName(QString::fromUtf8("Result"));

        verticalLayout_2->addWidget(Result);


        verticalLayout->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Form", "CAN_Setting", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Value Type\357\274\232", nullptr));
        Value_Type->setItemText(0, QCoreApplication::translate("Form", "Unsigned", nullptr));
        Value_Type->setItemText(1, QCoreApplication::translate("Form", "Signed", nullptr));

        label->setText(QCoreApplication::translate("Form", "Start Bit\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Length\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "Resolution\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Byte order\357\274\232", nullptr));
        Byte_order->setItemText(0, QCoreApplication::translate("Form", "Little(Intel)", nullptr));
        Byte_order->setItemText(1, QCoreApplication::translate("Form", "Big(Motorola)", nullptr));

        label_9->setText(QCoreApplication::translate("Form", "Offset\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Form", "Minimum/Maximum(Optional)", nullptr));
        label_10->setText(QCoreApplication::translate("Form", "Min\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("Form", "Max\357\274\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Form", "Data", nullptr));
        Data0->setText(QString());
        Data0->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Data1->setText(QString());
        Data1->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Data2->setText(QString());
        Data2->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Data3->setText(QString());
        Data3->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Data4->setText(QString());
        Data4->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Data5->setText(QString());
        Data5->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Data6->setText(QString());
        Data6->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Data7->setText(QString());
        Data7->setPlaceholderText(QCoreApplication::translate("Form", "FF", nullptr));
        Decode_Btn->setText(QCoreApplication::translate("Form", "Decode", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Form", "Result", nullptr));
        Result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAN_DECODE_UI_H
