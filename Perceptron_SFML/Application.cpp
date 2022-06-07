#include "Application.h"

Application::Application(int width, int height) : windowWidth(width), windowHeight(height)
{
    initWindow();
    createTrainers();

    prc = new Perceptron(3);
    line = new Line(window);
}

Application::~Application()
{

}

void Application::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Perceptron!");
    window->setFramerateLimit(60);

    sf::Vector2u windowSize = window->getSize();

    // Move the global origin to the centre of the viewport.
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(windowSize.x, windowSize.y));
    window->setView(view);

    // Get the native screen res.
    int nativeScreenWidth = sf::VideoMode::getDesktopMode().width;
    int nativeScreenHeight = sf::VideoMode::getDesktopMode().height;

    // Place the viewing window in the centre of the machines screen.
    window->setPosition(sf::Vector2i((nativeScreenWidth * 0.5f) - (windowWidth * 0.5f), (nativeScreenHeight * 0.5f) - (windowHeight * 0.5f)));
}

void Application::createTrainers()
{
    for (int i = 0; i < numOfTrainingPoints; ++i)
    {
        int randX = getRandValue();
        int randY = getRandValue();
        int answer = 1;                 // Default value assumes all points above the line +ve
        float funcAns = f(-randX);

        if (randY < funcAns)
        {
            answer = -1;                // If the randY point ends up below the line then ans = -ve
        }

        Trainer trainer(randX, randY, answer);

        training.push_back(trainer);
    }
}

int Application::getRandValue()
{
    int randVal = rand() % 145;

    // 50/50 chance to negate the value
    if (rand() % 2 == 0)
    {
        randVal = -randVal;
    }

    return randVal;
}

// Function of a line
float Application::f(float xPos)
{
    return 2 * xPos + 1;
}

void Application::update()
{
    int count = 0;

    while (window->isOpen() && count < 500)
    {
        pollEvents();
        runTraining();
        render();

        std::cout << "Training Session: " << count << '\n';

        ++count;
    }
}

void Application::pollEvents()
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
    }
}

void Application::runTraining()
{
    prc->train(training[count].inputs, training[count].answer);
    count = (count + 1) % training.size();
    //++count;

    for (int i = 0; i < count; ++i)
    {
        int guess = prc->feedForward(training[i].inputs);

        singlePoint = sf::CircleShape(6.0f);
        singlePoint.setOrigin(3.0f, 3.0f);
        singlePoint.setPosition(sf::Vector2f(training[i].inputs[0], training[i].inputs[1]));

        if (guess > 0)
        {
            singlePoint.setFillColor(sf::Color::Blue);
        }
        else
        {
            singlePoint.setFillColor(sf::Color::Yellow);
        }

        allPoints.push_back(singlePoint);
    }
}

void Application::beginDraw()
{
    window->clear();
}

void Application::endDraw()
{
    window->display();
}

void Application::render()
{
    beginDraw();

    line->render();

    for (int i = 0; i < allPoints.size(); ++i)
    {
        window->draw(allPoints[i]);
    }

    endDraw();
}
