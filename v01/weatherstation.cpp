#include "weatherstation.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateTime>

WeatherStation::WeatherStation(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("ReadyMario™ - Date and Time"));

    dateLabel = new QLabel(tr("Date:"));
    dateLineEdit = new QLineEdit;
    dateLineEdit->setReadOnly(true);

    timeLabel = new QLabel(tr("Time:"));
    timeLineEdit = new QLineEdit;
    timeLineEdit->setReadOnly(true);

    temperatureLabel = new QLabel(tr("Temperature:"));
    temperatureLineEdit = new QLineEdit;
    temperatureLineEdit->setReadOnly(true);

    humidityLabel = new QLabel(tr("Humidity:"));
    humidityLineEdit = new QLineEdit;
    humidityLineEdit->setReadOnly(true);

    altitudeLabel = new QLabel(tr("Altitude:"));
    altitudeLineEdit = new QLineEdit;
    altitudeLineEdit->setReadOnly(true);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(dateLabel, 0, 0);
    mainLayout->addWidget(dateLineEdit, 0, 1);
    mainLayout->addWidget(timeLabel, 1, 0);
    mainLayout->addWidget(timeLineEdit, 1, 1);
    mainLayout->addWidget(temperatureLabel, 2, 0);
    mainLayout->addWidget(temperatureLineEdit, 2, 1);
    mainLayout->addWidget(humidityLabel, 3, 0);
    mainLayout->addWidget(humidityLineEdit, 3, 1);
    mainLayout->addWidget(altitudeLabel, 4, 0);
    mainLayout->addWidget(altitudeLineEdit, 4, 1);
    setLayout(mainLayout);

    udpSocket.bind(5824);

    connect(&udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

WeatherStation::~WeatherStation()
{
}

void WeatherStation::processPendingDatagrams()
{
    QByteArray datagram;

    do
    {
        datagram.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(datagram.data(), datagram.size());
    } while (udpSocket.hasPendingDatagrams());

    QDateTime dateTime;
    double temperature;
    double humidity;
    double altitude;

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_3);
    in >> dateTime >> temperature >> humidity >> altitude;

    dateLineEdit->setText(dateTime.date().toString());
    timeLineEdit->setText(dateTime.time().toString());
    temperatureLineEdit->setText(tr("%1 C").arg(temperature));
    humidityLineEdit->setText(tr("%1%").arg(humidity));
    altitudeLineEdit->setText(tr("%1 m").arg(altitude));
}
