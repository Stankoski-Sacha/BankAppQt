## Main parts:

### QWidgets : Creates a window 
- resize(w,h) → resize the window
- setWindowTitle("Title") → set the title of the window
- show() → show the window


## Layouts:

### QHBoxLayout : Horizontal box layout for objects :

- addWidget(object) → add an object to the layout
- code :
``` cpp
    // Window
    auto window = std::make_unique<QWidget>();
    window->setWindowTitle("Hello World");
    window->resize(600, 600);

    // Buttons
    auto button = std::make_unique<QPushButton>("Hello World");
    auto button2 = std::make_unique<QPushButton>("Hello World2");
    auto button3 = std::make_unique<QPushButton>("Hello World3");
    auto button4 = std::make_unique<QPushButton>("Hello World4");
    auto button5 = std::make_unique<QPushButton>("Hello World5");

    // Layout
    auto layout = new QHBoxLayout(window.get());

    // Add buttons to window
    layout->addWidget(button.get());
    layout->addWidget(button2.get());
    layout->addWidget(button3.get());
    layout->addWidget(button4.get());
    layout->addWidget(button5.get());

    // Show the window
    window->show();

    // Delete the pointer
    delete layout;
```

### QVBoxLayout : Vertical box layout for objects :

- addWidget(object) -> add an object to the layout 
- code :
``` cpp
    // Window
    auto window = std::make_unique<QWidget>();
    window->setWindowTitle("Hello World");
    window->resize(600, 600);
    
    // Buttons
    auto button = std::make_unique<QPushButton>("Hello World");
    auto button2 = std::make_unique<QPushButton>("Hello World2");
    auto button3 = std::make_unique<QPushButton>("Hello World3");
    auto button4 = std::make_unique<QPushButton>("Hello World4");
    auto button5 = std::make_unique<QPushButton>("Hello World5");
    
    // Layout
    auto layout = new QVBoxLayout(window.get());
    
    // Add buttons to window
    layout->addWidget(button.get());
    layout->addWidget(button2.get());
    layout->addWidget(button3.get());
    layout->addWidget(button4.get());
    layout->addWidget(button5.get());
    
    // Show the window
    window->show();
    
    // Delete the pointer
    delete layout;
```

### QFormLayout : Form horizontal layouts with 2 objects on the same line like button and text boxes 
- addRow(object, object) -> add an object to the layout
- code :
``` cpp
    // Window
    auto window = std::make_unique<QWidget>();
    window->setWindowTitle("Hello World");

    // Buttons
    auto button = std::make_unique<QPushButton>("Hello World");
    auto button2 = std::make_unique<QPushButton>("Hello World2");
    auto button3 = std::make_unique<QPushButton>("Hello World3");
    auto button4 = std::make_unique<QPushButton>("Hello World4");
    auto button5 = std::make_unique<QPushButton>("Hello World5");

    auto edit = std::make_unique<QLineEdit>("Edit");
    auto edit2 = std::make_unique<QLineEdit>("Edit2");
    auto edit3 = std::make_unique<QLineEdit>("Edit3");
    auto edit4 = std::make_unique<QLineEdit>("Edit4");
    auto edit5 = std::make_unique<QLineEdit>("Edit5");


    // Layout
    auto layout = new QFormLayout(window.get());

    // Add buttons to window
    layout->addRow(button.get(), edit.get());
    layout->addRow(button2.get(), edit2.get());
    layout->addRow(button3.get(), edit3.get());
    layout->addRow(button4.get(), edit4.get());
    layout->addRow(button5.get(), edit5.get());

    // Show the window
    window->show();

    // Delete the pointer
    delete layout;
```

### QGridLayout : Grid layout for objects :
- AddWidget(object, row, column) -> add an object to the layout
- AddWidget(object, row, column, rowSpan, columnSpan) -> add an object to the layout
- code:
``` cpp
    // Create a new window
    auto window = std::make_unique<QWidget>();
    window->setWindowTitle("Hello World");
    window->resize(600, 600);

    // Buttons
    auto button = std::make_unique<QPushButton>("Hello World");
    auto button2 = std::make_unique<QPushButton>("Hello World2");
    auto button3 = std::make_unique<QPushButton>("Hello World3");
    auto button4 = std::make_unique<QPushButton>("Hello World4");
    auto button5 = std::make_unique<QPushButton>("Hello World5");


    // Layout
    auto layout = new QGridLayout(window.get());
    
    // Add widgets to the layout
    layout->addWidget(button.get(), 0, 0);
    layout->addWidget(button2.get(), 0, 1);
    layout->addWidget(button3.get(), 1, 0, 1, 2);
    layout->addWidget(button4.get(),2, 0);
    layout->addWidget(button5.get(), 2, 1);
    
    // Show the window
    window->show();

    // Delete the layout pointer to avoid memory leaks
    delete layout;
```

