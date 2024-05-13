#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "scene.h"
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QTimer>

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

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    int elapsedTime;
    void increaseElapsedTime();



};
#endif // MAINWINDOW_H
