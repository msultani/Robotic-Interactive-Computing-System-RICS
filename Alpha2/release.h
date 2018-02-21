#ifndef RELEASE_H
#define RELEASE_H
#include "functions.h"

#include <QDialog>
#include <QDebug>

namespace Ui {
class Release;
}

class Release : public QDialog
{
    Q_OBJECT
    friend class MainWindow;

public:
    explicit Release(QWidget *parent = 0);
    void countdown();
    ~Release();

private:
    Ui::Release *ui;
};

#endif // RELEASE_H
