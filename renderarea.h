#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT    // The Q_OBJECT macro must appear in the private section of a class definition that declares its own signals and slots or that uses other services provided by Qt's meta-object system.
public:
    explicit RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;  // This property holds the recommended minimum size for the widget.
    QSize sizeHint() const Q_DECL_OVERRIDE;         // This property holds the recommended size for the widget

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line, FutureCurve };

    void setBackgroundColor( QColor color) { mBackgroundColor = color; }    //setter
    QColor backgroundColor () const { return mBackgroundColor; }  // the const makes sure the function will not modify and member class variables

    void setShape (ShapeType shape) { mShape = shape; on_shape_changed(); }
    ShapeType shape() const { return mShape; }

    void setScale( float scale ) { mScale = scale; repaint(); }
    float scale() const { return mScale; }

    void setInterval( float interval ) { mIntervalLength = interval; repaint(); }
    float interval() const { return mIntervalLength; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:

private:
    void on_shape_changed();
    QPointF compute( float t );     // dispatch function based on mShape's type
    QPointF compute_astroid( float t);
    QPointF compute_cycloid( float t);
    QPointF compute_huygens( float t);
    QPointF compute_hypo( float t);
    QPointF compute_future_curve( float t );
    QPointF compute_line( float t );


private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;
};

#endif // RENDERAREA_H
