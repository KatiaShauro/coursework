#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "scene.h"
#include <QMainWindow>
#include <QGraphicsPixmapItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    Scene *scene;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
