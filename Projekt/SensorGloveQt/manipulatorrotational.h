#ifndef MANIPULATORROTATIONAL_H
#define MANIPULATORROTATIONAL_H

/*!
 * \file
 * \brief Definicja klasy ManipulatorRotational
 *
 * Plik zawiera definicję klasy ManipulatorRotational, która
 * jest klasą pochodną klasy QObject
 */

#include<QObject>
#include<Qt3DCore/QEntity>

#include"joint.h"

/*!
 * \brief Definiuje pojęcie manipulatora rotacyjnego
 *
 * Inicjuje pozycję stawow w przestrzeni trójwymiarowej
 */
class ManipulatorRotational: public QObject
{
    Q_OBJECT
protected:
    Qt3DCore::QEntity *m_rootEntity;
    QVector<Joint*> m_joints;
    QVector3D m_position;
    float m_rotation;
public:
    ManipulatorRotational(QVector<Joint*> p_joints,
                          QVector3D p_position=QVector3D(),
                          float p_rotation=float(),
                          Qt3DCore::QEntity *p_rootEntity=nullptr);

    ManipulatorRotational(const ManipulatorRotational& p_manipulator);

    void TransformJointAngles(QVector<float> p_jointAngles);
    Joint *getLastJoint();
    void setRotation(float p_rotation);
};

#endif // MANIPULATORROTATIONAL_H
