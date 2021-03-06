/****************************************************************************
** $Id: qwidgetstack.h,v 2.7.2.2 1998/08/19 16:02:45 agulbra Exp $
**
** Definition of QWidgetStack class
**
** Created : 980306
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of Qt Free Edition, version 1.45.
**
** See the file LICENSE included in the distribution for the usage
** and distribution terms, or http://www.troll.no/free-license.html.
**
** IMPORTANT NOTE: You may NOT copy this file or any part of it into
** your own programs or libraries.
**
** Please see http://www.troll.no/pricing.html for information about 
** Qt Professional Edition, which is this same library but with a
** license which allows creation of commercial/proprietary software.
**
*****************************************************************************/

#ifndef QWIDGETSTACK_H
#define QWIDGETSTACK_H

#ifndef QT_H
#include "qframe.h"
#include "qintdict.h"
#endif // QT_H


class QWidgetStackPrivate;

class QGridLayout;


class Q_EXPORT QWidgetStack: public QFrame
{
    Q_OBJECT
public:
    QWidgetStack( QWidget * parent = 0, const char * name = 0 );
    ~QWidgetStack();

    void addWidget( QWidget *, int );

    void removeWidget( QWidget * );

    void show();

    QWidget * widget( int ) const;
    int id( QWidget * ) const;

    QWidget * visibleWidget() const;
    
    bool event( QEvent * );

signals:
    void aboutToShow( int );
    void aboutToShow( QWidget * );

public slots:
    void raiseWidget( int );
    void raiseWidget( QWidget * );

protected:
    void frameChanged();

    void setChildGeometries();

private:
    bool isMyChild( QWidget * );
    QWidgetStackPrivate * d;
    QIntDict<QWidget> * dict;
    QGridLayout * l;
    QWidget * topWidget;
};


#endif
