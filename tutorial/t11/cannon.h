/****************************************************************
**
** Definition of CannonField class, Qt tutorial 11
**
****************************************************************/

#ifndef CANNON_H
#define CANNON_H

#include <qwidget.h>


class CannonField : public QWidget
{
    Q_OBJECT
public:
    CannonField( QWidget *parent=0, const char *name=0 );

    int   angle()      const { return ang; }
    int   force()      const { return f; }
    bool  isShooting() const { return shooting; }
public slots:
    void  setAngle( int degrees );
    void  setForce( int newton );
    void  shoot();
signals:
    void  angleChanged( int );
    void  forceChanged( int );
protected:
    void  timerEvent( QTimerEvent * );
    void  paintEvent( QPaintEvent * );
private:
    void  stopShooting();
    void  paintShot( QPainter * );
    void  paintCannon( QPainter * );
    QRect cannonRect() const;
    QRect shotRect() const;

    int   ang;
    int   f;
    bool  shooting;

    int   timerCount;
    float shoot_ang;
    float shoot_f;
};

#endif // CANNON_H
