/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lab_or;
    QLabel *lab_ed;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *but_start;
    QPushButton *but_stop;
    QPushButton *but_exit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *but_set1;
    QPushButton *but_set2;
    QPushButton *but_set3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(1438, 544);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 10, 1290, 521));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lab_or = new QLabel(layoutWidget);
        lab_or->setObjectName(QStringLiteral("lab_or"));
        sizePolicy.setHeightForWidth(lab_or->sizePolicy().hasHeightForWidth());
        lab_or->setSizePolicy(sizePolicy);
        lab_or->setMinimumSize(QSize(640, 480));
        lab_or->setFrameShape(QFrame::Panel);

        horizontalLayout_3->addWidget(lab_or);

        lab_ed = new QLabel(layoutWidget);
        lab_ed->setObjectName(QStringLiteral("lab_ed"));
        sizePolicy.setHeightForWidth(lab_ed->sizePolicy().hasHeightForWidth());
        lab_ed->setSizePolicy(sizePolicy);
        lab_ed->setMinimumSize(QSize(640, 480));
        lab_ed->setFrameShape(QFrame::Panel);

        horizontalLayout_3->addWidget(lab_ed);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        but_start = new QPushButton(layoutWidget);
        but_start->setObjectName(QStringLiteral("but_start"));

        horizontalLayout->addWidget(but_start);

        but_stop = new QPushButton(layoutWidget);
        but_stop->setObjectName(QStringLiteral("but_stop"));

        horizontalLayout->addWidget(but_stop);


        horizontalLayout_2->addLayout(horizontalLayout);

        but_exit = new QPushButton(layoutWidget);
        but_exit->setObjectName(QStringLiteral("but_exit"));

        horizontalLayout_2->addWidget(but_exit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(9, 9, 124, 456));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        but_set1 = new QPushButton(layoutWidget1);
        but_set1->setObjectName(QStringLiteral("but_set1"));

        verticalLayout->addWidget(but_set1);

        but_set2 = new QPushButton(layoutWidget1);
        but_set2->setObjectName(QStringLiteral("but_set2"));

        verticalLayout->addWidget(but_set2);

        but_set3 = new QPushButton(layoutWidget1);
        but_set3->setObjectName(QStringLiteral("but_set3"));

        verticalLayout->addWidget(but_set3);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 332, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260 \320\262\321\213\321\217\320\262\320\273\320\265\320\275\320\270\321\217 \320\264\320\262\320\270\320\266\321\203\321\211\320\270\321\205\321\201\321\217 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262 \320\275\320\260 \320\262\320\270\320\264\320\265\320\276\320\267\320\260\320\277\320\270\321\201\320\270", Q_NULLPTR));
        lab_or->setText(QString());
        lab_ed->setText(QString());
        but_start->setText(QApplication::translate("Widget", "\320\227\320\260\320\277\321\203\321\201\320\272", Q_NULLPTR));
        but_stop->setText(QApplication::translate("Widget", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260", Q_NULLPTR));
        but_exit->setText(QApplication::translate("Widget", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        but_set1->setText(QApplication::translate("Widget", "\320\240\320\265\320\266\320\270\320\274\n"
"\321\200\320\260\320\261\320\276\321\202\321\213", Q_NULLPTR));
        but_set2->setText(QApplication::translate("Widget", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270\n"
"\320\264\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", Q_NULLPTR));
        but_set3->setText(QApplication::translate("Widget", "\320\222\321\213\320\261\320\276\321\200\n"
"\320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
