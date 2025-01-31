#ifndef CHART_H
#define CHART_H

/*!
 * \file
 * \brief Definicja klasy Chart
 *
 * Plik zawiera definicję klasy Chart, która
 * jest klasą pochodną klasy QObject
 */

#include <QtCharts/QChart>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

/*!
 * \brief Modeluje pojęcie wykresu dynamicznego
 *
 * Inicjalizuje obiekt wykresu dynamicznego, który służy
 * do wyświetlania danych w kartezjańskim układzie współrzędnych.
 * Umożliwia dynamiczną modyfikację wykresu poprzez dodawanie
 * kolejnych waktości na koniec serii danych.
 */

class Chart: QObject
{
    Q_OBJECT
public:
    //Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    Chart(QChart *p_chart);
    virtual ~Chart();
    void addValue(float p_value);
    void setRangeX(float p_min, float p_max);
    void setRangeY(float p_min, float p_max);   
    QVector<float> getRangeX();
    void clearChart();
    float getMaxX(void);

public slots:
    void handleTimeout();

private:
    QChart *m_chart;
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axis;
    float m_step;
    float m_x;
    float m_y;
    float m_axisXminRange;
    float m_axisXmaxRange;
    float m_scrollSum;

};
//![1]


#endif // CHART_H
