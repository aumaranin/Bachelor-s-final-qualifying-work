/********************************************************************************
** Form generated from reading UI file 'work_mode.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORK_MODE_H
#define UI_WORK_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_work_mode
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rad_cam;
    QRadioButton *rad_vid;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *work_mode)
    {
        if (work_mode->objectName().isEmpty())
            work_mode->setObjectName(QStringLiteral("work_mode"));
        work_mode->resize(411, 129);
        widget = new QWidget(work_mode);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 391, 110));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rad_cam = new QRadioButton(widget);
        rad_cam->setObjectName(QStringLiteral("rad_cam"));
        rad_cam->setCheckable(true);
        rad_cam->setChecked(false);

        verticalLayout->addWidget(rad_cam);

        rad_vid = new QRadioButton(widget);
        rad_vid->setObjectName(QStringLiteral("rad_vid"));

        verticalLayout->addWidget(rad_vid);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(work_mode);

        QMetaObject::connectSlotsByName(work_mode);
    } // setupUi

    void retranslateUi(QDialog *work_mode)
    {
        work_mode->setWindowTitle(QApplication::translate("work_mode", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", Q_NULLPTR));
        rad_cam->setText(QApplication::translate("work_mode", "\320\232\320\260\320\274\320\265\321\200\320\260", Q_NULLPTR));
        rad_vid->setText(QApplication::translate("work_mode", "\320\222\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\321\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("work_mode", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("work_mode", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class work_mode: public Ui_work_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORK_MODE_H
