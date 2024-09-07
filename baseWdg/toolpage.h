#ifndef TOOLPAGE_H
#define TOOLPAGE_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class ToolPage;
}

class ToolPage : public QWidget
{
    Q_OBJECT

public:
    explicit ToolPage(QWidget *parent = nullptr);
    ~ToolPage();

private:
    Ui::ToolPage *ui;

public slots:
    void addWidget(const QString &title, QWidget *widget);

private slots:
    void on_pushButton_clicked();

private:
    void expand();
    void collapse();
    void initIcon();

private:
    bool m_bIsExpanded;

    QPixmap pixmap_open;
    QPixmap pixmap_close;
};

#endif // TOOLPAGE_H
