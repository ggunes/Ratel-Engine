#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QDockWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "Core/Engine.h"

class RatelEditor : public QMainWindow {
public:
    RatelEditor() {
        setWindowTitle("Ratel Engine Editor");
        resize(1280, 720);

        // Menü çubuğunu oluştur
        QMenuBar* menuBar = new QMenuBar(this);
        setMenuBar(menuBar);

        QMenu* fileMenu = menuBar->addMenu("Dosya");
        fileMenu->addAction("Yeni Proje", this, &RatelEditor::newProject);
        fileMenu->addAction("Aç", this, &RatelEditor::openProject);
        fileMenu->addAction("Kaydet", this, &RatelEditor::saveProject);
        fileMenu->addSeparator();
        fileMenu->addAction("Çıkış", this, &QWidget::close);

        // Proje gezgini paneli
        QDockWidget* projectDock = new QDockWidget("Proje Gezgini", this);
        projectDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        
        QFileSystemModel* fsModel = new QFileSystemModel;
        fsModel->setRootPath(QDir::currentPath());
        
        QTreeView* projectTree = new QTreeView;
        projectTree->setModel(fsModel);
        projectTree->setRootIndex(fsModel->index(QDir::currentPath()));
        
        projectDock->setWidget(projectTree);
        addDockWidget(Qt::LeftDockWidgetArea, projectDock);

        // Sahne görünümü
        QWidget* sceneWidget = new QWidget;
        setCentralWidget(sceneWidget);

        QVBoxLayout* sceneLayout = new QVBoxLayout(sceneWidget);
        QLabel* sceneLabel = new QLabel("Sahne Görünümü");
        sceneLayout->addWidget(sceneLabel);

        // Araç çubuğu
        QDockWidget* toolsDock = new QDockWidget("Araçlar", this);
        toolsDock->setAllowedAreas(Qt::RightDockWidgetArea);
        
        QWidget* toolsWidget = new QWidget;
        QVBoxLayout* toolsLayout = new QVBoxLayout(toolsWidget);
        
        QPushButton* runButton = new QPushButton("Çalıştır");
        connect(runButton, &QPushButton::clicked, this, &RatelEditor::runScene);
        
        toolsLayout->addWidget(runButton);
        toolsDock->setWidget(toolsWidget);
        
        addDockWidget(Qt::RightDockWidgetArea, toolsDock);
    }

private slots:
    void newProject() {
        QMessageBox::information(this, "Yeni Proje", "Yeni proje oluşturulacak");
    }

    void openProject() {
        QMessageBox::information(this, "Proje Aç", "Proje açılacak");
    }

    void saveProject() {
        QMessageBox::information(this, "Kaydet", "Proje kaydedilecek");
    }

    void runScene() {
        QMessageBox::information(this, "Çalıştır", "Sahne çalıştırılacak");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    RatelEditor editor;
    editor.show();
    return app.exec();
}