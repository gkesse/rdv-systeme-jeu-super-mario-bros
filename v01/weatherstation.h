#pragma once

#include <QDialog>
#include <QUdpSocket>

class QLabel;
class QLineEdit;

class WeatherStation : public QDialog
{
    Q_OBJECT

public:
    explicit WeatherStation(QWidget *parent = 0);
    ~WeatherStation();

private slots:
    void processPendingDatagrams();

private:
    QLabel *dateLabel;
    QLineEdit *dateLineEdit;

    QLabel *timeLabel;
    QLineEdit *timeLineEdit;

    QLabel *temperatureLabel;
    QLineEdit *temperatureLineEdit;

    QLabel *humidityLabel;
    QLineEdit *humidityLineEdit;

    QLabel *altitudeLabel;
    QLineEdit *altitudeLineEdit;

    QUdpSocket udpSocket;
};
