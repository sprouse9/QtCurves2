# Qt Parametric Curve Visualizer

This Qt Widgets project provides a visual exploration tool for rendering a variety of mathematical parametric curves using customizable settings. Users can change curve types, adjust rendering parameters (scale, interval, resolution), and pick colors dynamically through an interactive UI.

## 🎨 Features

- Renders the following parametric curves:
  - Astroid
  - Cycloid
  - Huygens Cycloid
  - Hypo Cycloid
  - Rose-style "FutureCurve"
  - Linear curve
- Interactive UI built with Qt Designer
- Color pickers for:
  - **Background**
  - **Curve (pen)**
- Controls for:
  - **Scale**
  - **Interval Length**
  - **Step Count (sampling resolution)**
- Dynamic rendering using Qt’s `QPainter`
- Clean separation of UI and logic (MVC-friendly)

## 🧱 Components

### `RenderArea` (Custom QWidget)

- Responsible for:
  - Drawing the selected shape
  - Applying transformation: parametric `t` → `QPointF` → screen space
  - Handling rendering logic with antialiasing and curve-specific equations
- Uses `QPainter::drawLine()` to draw curves segment-by-segment

### `MainWindow`

- Handles UI layout and connects button clicks and spinbox value changes to update the rendered scene
- Uses `QColorDialog` to allow real-time color selection

### Parametric Equations

Each curve is defined in its own function such as:

```cpp
QPointF RenderArea::compute_astroid(float t) {
    float x = 2 * pow(cos(t), 3);
    float y = 2 * pow(sin(t), 3);
    return QPointF(x, y);
}
```
### 📦 Project Structure
mainwindow.cpp/h: Main controller with UI interaction logic

renderarea.cpp/h: Custom drawing widget and curve logic

main.cpp: Application entry point

.ui: Qt Designer form describing the GUI layout
