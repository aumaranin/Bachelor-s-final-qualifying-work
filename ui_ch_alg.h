/********************************************************************************
** Form generated from reading UI file 'ch_alg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CH_ALG_H
#define UI_CH_ALG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ch_alg
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_alg1;
    QRadioButton *radioButton_alg2;
    QRadioButton *radioButton_alg3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ch_alg)
    {
        if (ch_alg->objectName().isEmpty())
            ch_alg->setObjectName(QStringLiteral("ch_alg"));
        ch_alg->resize(338, 129);
        verticalLayout_2 = new QVBoxLayout(ch_alg);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_alg1 = new QRadioButton(ch_alg);
        radioButton_alg1->setObjectName(QStringLiteral("radioButton_alg1"));

        verticalLayout->addWidget(radioButton_alg1);

        radioButton_alg2 = new QRadioButton(ch_alg);
        radioButton_alg2->setObjectName(QStringLiteral("radioButton_alg2"));

        verticalLayout->addWidget(radioButton_alg2);

        radioButton_alg3 = new QRadioButton(ch_alg);
        radioButton_alg3->setObjectName(QStringLiteral("radioButton_alg3"));

        verticalLayout->addWidget(radioButton_alg3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ch_alg);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ch_alg);

        QMetaObject::connectSlotsByName(ch_alg);
    } // setupUi

    void retranslateUi(QDialog *ch_alg)
    {
        ch_alg->setWindowTitle(QApplication::translate("ch_alg", "\320\222\321\213\320\261\320\276\321\200 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260 \320\276\320\261\320\275\320\260\321\200\321\203\320\266\320\265\320\275\320\270\321\217", Q_NULLPTR));
        radioButton_alg1->setText(QApplication::translate("ch_alg", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 Frame Difference (\321\200\320\260\320\267\320\275\320\270\321\206\320\260 \320\272\320\260\320\264\321\200\320\276\320\262)", Q_NULLPTR));
        radioButton_alg2->setText(QApplication::translate("ch_alg", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 MeanBGS (\320\262\321\213\321\207\320\270\321\202\320\260\320\275\320\270\320\265 \321\204\320\276\320\275\320\260)", Q_NULLPTR));
        radioButton_alg3->setText(QApplication::translate("ch_alg", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 Gaussian (\321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\320\265 \320\223\320\260\321\203\321\201\321\201\320\260)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ch_alg", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ch_alg: public Ui_ch_alg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CH_ALG_H
