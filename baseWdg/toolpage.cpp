#include "toolpage.h"
#include "ui_toolpage.h"
#include "quiwidget.h"
#include "iconfont.h"

#define OPEN_ICON  ":/new/prefix1/WidgetContains/icon_down.png"
#define CLOSE_ICON ":/new/prefix1/WidgetContains/icon_upward.png"

ToolPage::ToolPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolPage),
    m_bIsExpanded(true)
{
    ui->setupUi(this);

//    ui->btnData->setIcon(IconHelper::Instance()->getPixmap(QUIConfig::TextColor, 0xf002, 20, 20, 20));
    pixmap_open = IconHelper::Instance()->getPixmap(QUIConfig::TextColor, 0xf103, 20, 20, 20);//QPixmap(OPEN_ICON);
    pixmap_close = IconHelper::Instance()->getPixmap(QUIConfig::TextColor, 0xf102, 20, 20, 20);//QPixmap(CLOSE_ICON);

//    ui->contentWidget->setAttribute(Qt::WA_StyledBackground);
//    ui->lockerButton->SetImageLabel(pixmap_open);
//    ui->pushButton->setIcon(QIcon("OPEN_ICON"));
//    initIcon();
}

ToolPage::~ToolPage()
{
    delete ui;
}

void ToolPage::addWidget(const QString &title, QWidget *widget)
{
//    ui->lockerButton->SetTextLabel(title);
    ui->verticalLayout_2->addWidget(widget);

    initIcon();
    ui->pushButton->setText(title);
}

void ToolPage::expand()
{
    ui->contentWidget->show();
    ui->pushButton->setIcon(pixmap_open);
    m_bIsExpanded = true;
}

void ToolPage::collapse()
{
    ui->contentWidget->hide();
    ui->pushButton->setIcon(pixmap_close);
    m_bIsExpanded = false;
}

void ToolPage::initIcon()
{
    ui->pushButton->setFixedHeight(30);
//    ui->pushButton->setIconSize(QSize(30, 20));
    ui->pushButton->setIcon(pixmap_open/*IconFont::Instance()->getPixmap(QUIConfig::TextColor, 0xea44, 20, 30, 20)*/);
}

//void ToolPage::on_lockerButton_clicked()
//{
//    if (m_bIsExpanded){
//        collapse();
//        ui->lockerButton->SetImageLabel(pixmap_close);
//    }
//    else{
//        expand();
//        ui->lockerButton->SetImageLabel(pixmap_open);
//    }
//}

void ToolPage::on_pushButton_clicked()
{
    if (m_bIsExpanded){
        collapse();
    }
    else{
        expand();
    }
}
