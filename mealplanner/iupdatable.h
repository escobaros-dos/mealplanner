#ifndef IUPDATABLE_H
#define IUPDATABLE_H

#include <QLabel>
#include <QWidget>
#include <QObject>
#include "ingredient.h"
#include <QVector>

//HOW TO USE:

//The protected methods: CloseWindow, UpdateNutrition, SetLabels, and UpdateStatus, are non virtual and
// and general enough to be used with any widget that needs them
// the UpdateMethod is virtual and NEEDS to be overridded in the class, this means a declaration of same
// type and name in the .h and its own unique implementation in the .cpp
// the UpdateMethod implementation is already written, seen lines 61-64. so thats already done.
// UpdateMethod function is NEVER called by the class, only by the interface.
// The widget class only calls the proecte methods mentioned above.  So when you hit the back button signal, have it
// call the CloseWindow(this); function
// Call UpdateNutrition with a vector of the labels to be updated, the protien, calore, fat and carbs input labels
// For the view meal details you dont need to use SetLables

// Don't use UpdateStatus for now....


class IUpdatable
{
public:
     //virtual Iupdatable();
     //virtual ~Iupdatable();
protected:

    void CloseWindow(QWidget*);
    void UpdateNutrition(const QVector<QLabel*>& Labels);
    void SetLabels(const QVector<QLabel*>& L, int value);
    void UpdateStatus(QLabel*, const QString&);


    int prt = 0;
    int cal = 0;
    int car = 0;
    int fat = 0;

private:
    //virtual void RealTimeUpdate(int s, QVector<int>& Values);
    //virtual void UpdateByCopy(QVector<int>& Values);
    virtual void UpdateMethod() = 0;

        // want the recipe class to have access to these variables so can be assigned to itself
};

#define Updatable_iid "com.acme.Updatable"

Q_DECLARE_INTERFACE(IUpdatable, Updatable_iid)


#endif // IUPDATABLE_H
