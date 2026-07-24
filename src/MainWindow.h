#include "MainWindow.h"

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

#include <QDoubleSpinBox>
#include <QSpinBox>

#include <QFileDialog>
#include <QProgressBar>

#include <QSettings>
#include <QGroupBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    loadSettings();
}


void MainWindow::setupUi()
{
    setWindowTitle("TimeStretch 2026");

    resize(850,650);


    QWidget *central = new QWidget(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(central);



    // Files section

    QGroupBox *fileBox = new QGroupBox("Files");

    QGridLayout *fileLayout = new QGridLayout(fileBox);


    inputFileEdit = new QLineEdit();

    QPushButton *inputButton =
        new QPushButton("Browse...");


    outputFolderEdit = new QLineEdit();

    QPushButton *outputButton =
        new QPushButton("Browse...");


    fileLayout->addWidget(
        new QLabel("Input Audio"),
        0,0);

    fileLayout->addWidget(
        inputFileEdit,
        0,1);

    fileLayout->addWidget(
        inputButton,
        0,2);



    fileLayout->addWidget(
        new QLabel("Output Folder"),
        1,0);

    fileLayout->addWidget(
        outputFolderEdit,
        1,1);

    fileLayout->addWidget(
        outputButton,
        1,2);



    mainLayout->addWidget(fileBox);



    // DSP controls

    QGroupBox *dspBox =
        new QGroupBox("Time Stretch Parameters");


    QGridLayout *dspLayout =
        new QGridLayout(dspBox);


    stretchSpin =
        new QDoubleSpinBox();

    stretchSpin->setRange(
        0.05,
        20.0);

    stretchSpin->setSingleStep(
        0.05);

    stretchSpin->setValue(
        1.0);



    pitchSpin =
        new QDoubleSpinBox();

    pitchSpin->setRange(
        -48,
        48);

    pitchSpin->setValue(
        0);



    blockSpin =
        new QSpinBox();

    blockSpin->setRange(
        10,
        500);

    blockSpin->setValue(
        120);



    overlapSpin =
        new QSpinBox();

    overlapSpin->setRange(
        1,
        32);

    overlapSpin->setValue(
        4);



    dspLayout->addWidget(
        new QLabel("Stretch"),
        0,0);

    dspLayout->addWidget(
        stretchSpin,
        0,1);



    dspLayout->addWidget(
        new QLabel("Pitch (semitones)"),
        1,0);

    dspLayout->addWidget(
        pitchSpin,
        1,1);



    dspLayout->addWidget(
        new QLabel("Block (ms)"),
        2,0);

    dspLayout->addWidget(
        blockSpin,
        2,1);



    dspLayout->addWidget(
        new QLabel("Overlap"),
        3,0);

    dspLayout->addWidget(
        overlapSpin,
        3,1);



    mainLayout->addWidget(dspBox);



    processButton =
        new QPushButton(
            "Process Audio");


    progressBar =
        new QProgressBar();

    progressBar->setValue(0);



    mainLayout->addWidget(processButton);

    mainLayout->addWidget(progressBar);



    setCentralWidget(central);



    connect(
        inputButton,
        &QPushButton::clicked,
        this,
        &MainWindow::browseInputFile);



    connect(
        outputButton,
        &QPushButton::clicked,
        this,
        &MainWindow::browseOutputFolder);



    connect(
        processButton,
        &QPushButton::clicked,
        this,
        &MainWindow::processAudio);
}



void MainWindow::browseInputFile()
{
    QString file =
        QFileDialog::getOpenFileName(
            this,
            "Select Audio File",
            "",
            "Audio Files (*.wav *.flac *.aiff *.mp3)"
        );


    if(!file.isEmpty())
        inputFileEdit->setText(file);
}



void MainWindow::browseOutputFolder()
{
    QString folder =
        QFileDialog::getExistingDirectory(
            this,
            "Select Output Folder");


    if(!folder.isEmpty())
        outputFolderEdit->setText(folder);
}



void MainWindow::processAudio()
{
    progressBar->setValue(0);

    // DSP engine will be added in Milestone 3
}



void MainWindow::loadSettings()
{
    QSettings settings(
        "TimeStretch2026",
        "Application");


    inputFileEdit->setText(
        settings.value(
            "inputFolder",
            "").toString());


    outputFolderEdit->setText(
        settings.value(
            "outputFolder",
            "").toString());


    stretchSpin->setValue(
        settings.value(
            "stretch",
            1.0).toDouble());


    pitchSpin->setValue(
        settings.value(
            "pitch",
            0).toDouble());


    blockSpin->setValue(
        settings.value(
            "block",
            120).toInt());


    overlapSpin->setValue(
        settings.value(
            "overlap",
            4).toInt());
}



void MainWindow::saveSettings()
{
    QSettings settings(
        "TimeStretch2026",
        "Application");


    settings.setValue(
        "inputFolder",
        inputFileEdit->text());


    settings.setValue(
        "outputFolder",
        outputFolderEdit->text());


    settings.setValue(
        "stretch",
        stretchSpin->value());


    settings.setValue(
        "pitch",
        pitchSpin->value());


    settings.setValue(
        "block",
        blockSpin->value());


    settings.setValue(
        "overlap",
        overlapSpin->value());
}
~MainWindow()
{
    saveSettings();
}
