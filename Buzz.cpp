/*
Author: Haotian Liu
Last Date Modified: Oct.23
*/

#include <sfml/Graphics.hpp>
#include <sfml/Audio.hpp>
#include <sstream>
#include<iostream>
#include <random>
#include<math.h>
#include <ctype.h>
#include<stdio.h>
#define PI 3.1415926
using namespace sf;
using namespace std;

int main()
{


    // Create and open a window for the game
    RenderWindow window(VideoMode(1920, 1080), "Buzzy Revenge", Style::Fullscreen);

    //set the background
    Texture background;
    background.loadFromFile("graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(background);
    spriteBackground.setPosition(0, 0);

    // set the font
    Text messageTextname;
    Text messageTextEnter;
    Text messageTextEsc;
    Text messageTextSpace;
    Text messageTextUpdown;
    Text messageTextAuthor;
    Text messageTextLive;
    Text messageTextPower;
    Text scoreText;
    Text scoreText1;
    Text messageTextGameover;
    Font font;
    font.loadFromFile("graphics/KOMIKAP_.ttf");



    messageTextname.setFont(font);
    messageTextname.setString("Buzzy's Revenge");
    messageTextname.setCharacterSize(75);
    messageTextname.setFillColor(Color::Red);
    FloatRect textRectname = messageTextname.getLocalBounds();
    messageTextname.setOrigin(textRectname.left +
        textRectname.width / 2.0f,
        textRectname.top +
        textRectname.height / 2.0f);
    messageTextname.setPosition(1920 / 2.0f, 200.0f);

    messageTextEnter.setFont(font);
    messageTextEnter.setString("Press Enter to Restart");
    messageTextEnter.setCharacterSize(50);
    messageTextEnter.setFillColor(Color::White);
    FloatRect textRectEnter = messageTextEnter.getLocalBounds();
    messageTextEnter.setOrigin(textRectEnter.left +
        textRectEnter.width / 2.0f,
        textRectEnter.top +
        textRectEnter.height / 2.0f);
    messageTextEnter.setPosition(1920 / 2.0f, 300.0f);


    messageTextEsc.setFont(font);
    messageTextEsc.setString("Press Esc to Exit");
    messageTextEsc.setCharacterSize(50);
    messageTextEsc.setFillColor(Color::White);
    FloatRect textRectEsc = messageTextEsc.getLocalBounds();
    messageTextEsc.setOrigin(textRectEsc.left +
        textRectEsc.width / 2.0f,
        textRectEsc.top +
        textRectEsc.height / 2.0f);
    messageTextEsc.setPosition(1920 / 2.0f, 400.0f);

    messageTextSpace.setFont(font);
    messageTextSpace.setString("Press Space to Powerup");
    messageTextSpace.setCharacterSize(50);
    messageTextSpace.setFillColor(Color::White);
    FloatRect textRectSpace = messageTextSpace.getLocalBounds();
    messageTextSpace.setOrigin(textRectSpace.left +
        textRectSpace.width / 2.0f,
        textRectSpace.top +
        textRectSpace.height / 2.0f);
    messageTextSpace.setPosition(1920 / 2.0f, 500.0f);

    messageTextUpdown.setFont(font);
    messageTextUpdown.setString("Press up/down arrow to Aim");
    messageTextUpdown.setCharacterSize(50);
    messageTextUpdown.setFillColor(Color::White);
    FloatRect textRectUpdown = messageTextUpdown.getLocalBounds();
    messageTextUpdown.setOrigin(textRectUpdown.left +
        textRectUpdown.width / 2.0f,
        textRectUpdown.top +
        textRectUpdown.height / 2.0f);
    messageTextUpdown.setPosition(1920 / 2.0f, 600.0f);

    messageTextAuthor.setFont(font);
    messageTextAuthor.setString("Created by Haotian Liu");
    messageTextAuthor.setCharacterSize(35);
    messageTextAuthor.setFillColor(Color::White);
    FloatRect textRectAuthor = messageTextAuthor.getLocalBounds();
    messageTextAuthor.setOrigin(textRectAuthor.left +
        textRectAuthor.width / 2.0f,
        textRectAuthor.top +
        textRectAuthor.height / 2.0f);
    messageTextAuthor.setPosition(1920 / 2.0f, 675.0f);

    messageTextLive.setFont(font);
    messageTextLive.setString("Lives");
    messageTextLive.setCharacterSize(40);
    messageTextLive.setFillColor(Color::White);
    FloatRect textRectLive = messageTextLive.getLocalBounds();
    messageTextLive.setOrigin(textRectLive.left +
        textRectLive.width / 2.0f,
        textRectLive.top +
        textRectLive.height / 2.0f);
    messageTextLive.setPosition(80.0f, 60.0f);

    messageTextPower.setFont(font);
    messageTextPower.setString("Power");
    messageTextPower.setCharacterSize(40);
    messageTextPower.setFillColor(Color::White);
    FloatRect textRectPower = messageTextPower.getLocalBounds();
    messageTextPower.setOrigin(textRectPower.left +
        textRectPower.width / 2.0f,
        textRectPower.top +
        textRectPower.height / 2.0f);
    messageTextPower.setPosition(80.0f, 1000.0f);

    messageTextGameover.setFont(font);
    messageTextGameover.setString("Game Over");
    messageTextGameover.setCharacterSize(150);
    messageTextGameover.setFillColor(Color::Red);
    FloatRect textRectGameover = messageTextGameover.getLocalBounds();
    messageTextGameover.setOrigin(textRectGameover.left +
        textRectGameover.width / 2.0f,
        textRectGameover.top +
        textRectGameover.height / 2.0f);
    messageTextGameover.setPosition(1920 / 2.0f, 1080 / 2.0f);



    scoreText.setFont(font);
    scoreText.setString("Score:0");
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(Color::White);
    FloatRect textRectscore = scoreText.getLocalBounds();
    scoreText.setOrigin(textRectscore.left +
        textRectscore.width / 2.0f,
        textRectscore.top +
        textRectscore.height / 2.0f);
    scoreText.setPosition(1750.0f, 60.0f);

    scoreText1.setFont(font);
    scoreText1.setString("Score:0");
    scoreText1.setCharacterSize(80);
    scoreText1.setFillColor(Color::White);
    FloatRect textRectscore1 = scoreText1.getLocalBounds();
    scoreText1.setOrigin(textRectscore1.left +
        textRectscore1.width / 2.0f,
        textRectscore1.top +
        textRectscore1.height / 2.0f);
    scoreText1.setPosition(1920 / 2.0f, 750.0f);





    //set the buzz
    Texture textureBuzz;
    textureBuzz.loadFromFile("graphics/smallbuzzy.png");
    Sprite spriteBuzz;
    spriteBuzz.setTexture(textureBuzz);
    spriteBuzz.setScale(0.8f, 0.8f);
    FloatRect originBuzz = spriteBuzz.getLocalBounds();
    spriteBuzz.setOrigin(originBuzz.left +
        originBuzz.width / 2.0f,
        originBuzz.top +
        originBuzz.height / 2.0f);
    spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
    sf::Vector2f scale = spriteBuzz.getScale();




    //prepare the evil mascots
    Texture textureEtiger;
    textureEtiger.loadFromFile("graphics/tiger.png");
    Sprite spriteEtiger;
    spriteEtiger.setTexture(textureEtiger);
    spriteEtiger.setScale(0.15f, 0.15f);
    FloatRect originEtiger = spriteEtiger.getLocalBounds();
    spriteEtiger.setOrigin(originEtiger.left +
        originEtiger.width / 2.0f,
        originEtiger.top +
        originEtiger.height / 2.0f);
    spriteEtiger.setPosition(1650.0f, 500.0f);


    Texture textureEBulldogs;
    textureEBulldogs.loadFromFile("graphics/Bulldogs.png");
    Sprite spriteEBulldogs;
    spriteEBulldogs.setTexture(textureEBulldogs);
    spriteEBulldogs.setScale(1.5f, 1.5f);
    FloatRect originEBulldogs = spriteEBulldogs.getLocalBounds();
    spriteEBulldogs.setOrigin(originEBulldogs.left +
        originEBulldogs.width / 2.0f,
        originEBulldogs.top +
        originEBulldogs.height / 2.0f);
    spriteEBulldogs.setPosition(1800.0f, 500.0f);

    // prepare the wood creatures

    Texture textureSheep;
    textureSheep.loadFromFile("graphics/sheep.png");
    Sprite spriteSheep;
    spriteSheep.setTexture(textureSheep);
    spriteSheep.setScale(1.4f, 1.4f);
    FloatRect originSheep = spriteSheep.getLocalBounds();
    spriteSheep.setOrigin(originSheep.left +
        originSheep.width / 2.0f,
        originSheep.top +
        originSheep.height / 2.0f);
    spriteSheep.setPosition(1650.0f, 650.0f);

    Texture textureBunny;
    textureBunny.loadFromFile("graphics/bunny.png");
    Sprite spriteBunny;
    spriteBunny.setTexture(textureBunny);
    spriteBunny.setScale(1.4f, 1.4f);
    FloatRect originBunny = spriteBunny.getLocalBounds();
    spriteBunny.setOrigin(originBunny.left +
        originBunny.width / 2.0f,
        originBunny.top +
        originBunny.height / 2.0f);
    spriteBunny.setPosition(1650.0f, 350.0f);

    Texture textureDog;
    textureDog.loadFromFile("graphics/dog.png");
    Sprite spriteDog;
    spriteDog.setTexture(textureDog);
    spriteDog.setScale(1.4f, 1.4f);
    FloatRect originDog = spriteDog.getLocalBounds();
    spriteDog.setOrigin(originDog.left +
        originDog.width / 2.0f,
        originDog.top +
        originDog.height / 2.0f);
    spriteDog.setPosition(1650.0f, 800.0f);

    Texture textureMouse;
    textureMouse.loadFromFile("graphics/mouse.png");
    Sprite spriteMouse;
    spriteMouse.setTexture(textureMouse);
    spriteMouse.setScale(1.4f, 1.4f);
    FloatRect originMouse = spriteMouse.getLocalBounds();
    spriteMouse.setOrigin(originMouse.left +
        originMouse.width / 2.0f,
        originMouse.top +
        originMouse.height / 2.0f);
    spriteMouse.setPosition(1650.0f, 950.0f);



    Texture textureUnicorn;
    textureUnicorn.loadFromFile("graphics/unicorn.png");
    Sprite spriteUnicorn;
    spriteUnicorn.setTexture(textureUnicorn);
    spriteUnicorn.setScale(1.3f, 1.3f);
    FloatRect originUnicorn = spriteUnicorn.getLocalBounds();
    spriteUnicorn.setOrigin(originUnicorn.left +
        originUnicorn.width / 2.0f,
        originUnicorn.top +
        originUnicorn.height / 2.0f);
    spriteUnicorn.setPosition(1800.0f, 350.0f);

    Texture textureFrog;
    textureFrog.loadFromFile("graphics/frog.png");
    Sprite spriteFrog;
    spriteFrog.setTexture(textureFrog);
    spriteFrog.setScale(1.4f, 1.4f);
    FloatRect originFrog = spriteFrog.getLocalBounds();
    spriteFrog.setOrigin(originFrog.left +
        originFrog.width / 2.0f,
        originFrog.top +
        originFrog.height / 2.0f);
    spriteFrog.setPosition(1800.0f, 650.0f);

    Texture texturePig;
    texturePig.loadFromFile("graphics/pig.png");
    Sprite spritePig;
    spritePig.setTexture(texturePig);
    spritePig.setScale(1.4f, 1.4f);
    FloatRect originPig = spritePig.getLocalBounds();
    spritePig.setOrigin(originPig.left +
        originPig.width / 2.0f,
        originPig.top +
        originPig.height / 2.0f);
    spritePig.setPosition(1800.0f, 800.0f);

    Texture textureChicken;
    textureChicken.loadFromFile("graphics/chicken.png");
    Sprite spriteChicken;
    spriteChicken.setTexture(textureChicken);
    spriteChicken.setScale(1.4f, 1.4f);
    FloatRect originChicken = spriteChicken.getLocalBounds();
    spriteChicken.setOrigin(originChicken.left +
        originChicken.width / 2.0f,
        originChicken.top +
        originChicken.height / 2.0f);
    spriteChicken.setPosition(1800.0f, 950.0f);

    //prepare the insect
    Texture textureInsect;
    textureInsect.loadFromFile("graphics/insect.png");
    Sprite spriteInsect;
    spriteInsect.setTexture(textureInsect);
    spriteInsect.setScale(-1.9f, 1.9f);
    FloatRect originInsect = spriteInsect.getLocalBounds();
    spriteInsect.setOrigin(originInsect.left +
        originInsect.width / 2.0f,
        originInsect.top +
        originInsect.height / 2.0f);

    spriteInsect.setPosition(1800.0f, 250.0f);




    //set the power bar
    RectangleShape powerBar;
    float powerBarWidth = 10;
    float powerBarHeight = 80;
    float powerBarEWidth = 400;
    powerBar.setSize(Vector2f(powerBarWidth, powerBarHeight));
    powerBar.setFillColor(Color::Red);

    powerBar.setOrigin(0.0f, powerBarHeight / 2.0f);

    powerBar.setPosition(200.0f, 1000.0f);

    //set the buzzylife 
    Texture textureBuzzlife;
    textureBuzzlife.loadFromFile("graphics/buzzy life.png");
    Sprite spriteLife1;
    spriteLife1.setTexture(textureBuzzlife);
    spriteLife1.setScale(0.8f, 0.8f);
    FloatRect originLife1 = spriteLife1.getLocalBounds();
    spriteLife1.setOrigin(originLife1.left +
        originLife1.width / 2.0f,
        originLife1.top +
        originLife1.height / 2.0f);

    spriteLife1.setPosition(200.0f, 60.0f);

    Sprite spriteLife2;
    spriteLife2.setTexture(textureBuzzlife);
    spriteLife2.setScale(0.8f, 0.8f);
    FloatRect originLife2 = spriteLife2.getLocalBounds();
    spriteLife2.setOrigin(originLife2.left +
        originLife2.width / 2.0f,
        originLife2.top +
        originLife2.height / 2.0f);

    spriteLife2.setPosition(300.0f, 60.0f);

    Sprite spriteLife3;
    spriteLife3.setTexture(textureBuzzlife);
    spriteLife3.setScale(0.8f, 0.8f);
    FloatRect originLife3 = spriteLife3.getLocalBounds();
    spriteLife3.setOrigin(originLife3.left +
        originLife3.width / 2.0f,
        originLife3.top +
        originLife3.height / 2.0f);

    spriteLife3.setPosition(400.0f, 60.0f);

    Sprite spriteLife4;
    spriteLife4.setTexture(textureBuzzlife);
    spriteLife4.setScale(0.8f, 0.8f);
    FloatRect originLife4 = spriteLife4.getLocalBounds();
    spriteLife4.setOrigin(originLife4.left +
        originLife4.width / 2.0f,
        originLife4.top +
        originLife4.height / 2.0f);

    spriteLife4.setPosition(500.0f, 60.0f);

    Sprite spriteLife5;
    spriteLife5.setTexture(textureBuzzlife);
    spriteLife5.setScale(0.8f, 0.8f);
    FloatRect originLife5 = spriteLife5.getLocalBounds();
    spriteLife5.setOrigin(originLife5.left +
        originLife5.width / 2.0f,
        originLife5.top +
        originLife5.height / 2.0f);

    spriteLife5.setPosition(600.0f, 60.0f);

    //prepare the sound
    SoundBuffer launchBuffer;
    launchBuffer.loadFromFile("sound/chop.wav");
    Sound Lau;
    Lau.setBuffer(launchBuffer);

    SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("sound/death.wav");
    Sound death;
    death.setBuffer(deathBuffer);

    // Gameover
    SoundBuffer overBuffer;
    overBuffer.loadFromFile("sound/out_of_time.wav");
    Sound Gameover;
    Gameover.setBuffer(overBuffer);




    //variable
    bool textactive = true;
    bool rotate = true;
    bool power = true;
    bool launch = false;
    bool launcha = true;
    bool relevel = true;
    bool gameover = false;
    bool soundover = false;

    bool Tigeralive = true;
    bool Bulldogalive = true;
    bool Unicornalive = true;
    bool Insectalive = true;
    bool Insectpath1 = false;
    bool Insectpath2 = false;
    bool Insectpath3 = false;
    bool Insectpath4 = false;
    bool Insectpath5 = false;
    bool path = true;

    bool collisionwood = false;



    float angle = 0.0f;
    float buzzvi = 500.0f;
    float buzzvmax = 3000.0f;
    float powerBarWidthperv = powerBarEWidth / buzzvmax;
    float tBuzz = 0.0f;
    float tBuzz1 = 0.0f;
    float XBuzz = 0.0f;
    float YBuzz = 0.0f;

    float XBuzzi = 0.0f;
    float YBuzzi = 0.0f;

    float XBuzz1 = 0.0f;
    float YBuzz1 = 0.0f;

    float Insectvi = 300.0f;
    float tInsect = 0.0f;
    float XInsecti = 1800.0f;
    float XInsect = 0.0f;
    float YInsecti = 0.0f;



    int score = 0;
    int lives = 5;
    int b1 = 0;
    int b2 = 0;



    //set the clock
    Clock clock;
    Clock Insect;
    Clock Dis;

    //prepare the randow variable
    random_device rd;
    default_random_engine generator{ rd() };
    uniform_int_distribution<int>placement1(0, 2);
    uniform_int_distribution<int>placement2(0, 4);
    uniform_int_distribution<int>placement3(0, 4);










    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {

            }

        }
        // esc to escape the game
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }



        // up and down to rotate the buzz and set the original angle
        if (Keyboard::isKeyPressed(Keyboard::Up) && rotate)
        {
            if (angle >= -90.0f)
            {
                angle = angle - 0.1f;
                spriteBuzz.setRotation(angle);
            }
            else
            {
                angle = -90.0f;
                spriteBuzz.setRotation(angle);
            }



        }

        if (Keyboard::isKeyPressed(Keyboard::Down) && rotate)
        {

            if (angle <= 90.0f)
            {
                angle = angle + 0.1f;
                spriteBuzz.setRotation(angle);
            }
            else
            {
                angle = 90.0f;
                spriteBuzz.setRotation(angle);
            }

        }
        // set the power using space
        if (Keyboard::isKeyPressed(Keyboard::Space) && power)
        {
            launcha = true;
            if (buzzvi <= buzzvmax)
            {
                buzzvi = buzzvi + 5.0f;
                powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));


            }
            else
            {
                buzzvi = 5.0f;
            }

        }
        // restart the game pressing Enter
        if (Keyboard::isKeyPressed(Keyboard::Enter))

        {
            buzzvi = 500.0f;
            tBuzz = 0.0f;
            spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
            spriteBuzz.setRotation(0.0f);
            powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));
            textactive = true;
            rotate = true;
            power = true;
            launch = false;
            Bulldogalive = true;
            Tigeralive = true;
            Unicornalive = true;
            Insectalive = true;
            relevel = true;
            gameover = false;
            soundover = false;
            score = 0;
            lives = 5;

        }
        //Launch the buzz if we release the space
        if (!(Keyboard::isKeyPressed(Keyboard::Space)) && buzzvi != 500.0f && launcha)
        {

            textactive = false;
            launcha = false;
            launch = true;
            clock.restart();
            rotate = false;
            power = false;
            Lau.play();
        }

        // set the randow positions when recreating the level
        if (relevel)
        {
            int a1 = placement1(generator);
            int a2 = placement2(generator);
            b1 = a1;
            switch (a1)
            {
            case 0:
                spriteEtiger.setPosition(1650.0f, 350.0f);
                spriteSheep.setPosition(1650.0f, 500.0f);
                spriteMouse.setPosition(1650.0f, 650.0f);
                spriteBunny.setPosition(1650.0f, 800.0f);
                spriteDog.setPosition(1650.0f, 950.0f);
                break;
            case 1:
                spriteEtiger.setPosition(1650.0f, 650.0f);
                spriteSheep.setPosition(1650.0f, 800.0f);
                spriteMouse.setPosition(1650.0f, 500.0f);
                spriteBunny.setPosition(1650.0f, 950.0f);
                spriteDog.setPosition(1650.0f, 350.0f);
                break;
            case 2:
                spriteEtiger.setPosition(1650.0f, 800.0f);
                spriteSheep.setPosition(1650.0f, 500.0f);
                spriteMouse.setPosition(1650.0f, 950.0f);
                spriteBunny.setPosition(1650.0f, 350.0f);
                spriteDog.setPosition(1650.0f, 650.0f);
            default:
                break;
            }
            switch (a2)
            {
            case 0:
                spriteEBulldogs.setPosition(1800.0f, 500.0f);
                spriteFrog.setPosition(1800.0f, 350.0f);
                spritePig.setPosition(1800.0f, 650.0f);
                spriteChicken.setPosition(1800.0f, 800.0f);
                spriteUnicorn.setPosition(1800.0f, 950.0f);
                break;
            case 1:
                spriteEBulldogs.setPosition(1800.0f, 650.0f);
                spriteFrog.setPosition(1800.0f, 800.0f);
                spritePig.setPosition(1800.0f, 500.0f);
                spriteChicken.setPosition(1800.0f, 950.0f);
                spriteUnicorn.setPosition(1800.0f, 350.0f);
                break;
            case 2:
                spriteEBulldogs.setPosition(1800.0f, 950.0f);
                spriteFrog.setPosition(1800.0f, 800.0f);
                spritePig.setPosition(1800.0f, 650.0f);
                spriteChicken.setPosition(1800.0f, 350.0f);
                spriteUnicorn.setPosition(1800.0f, 500.0f);
                break;
            case 3:
                spriteEBulldogs.setPosition(1800.0f, 950.0f);
                spriteFrog.setPosition(1800.0f, 800.0f);
                spritePig.setPosition(1800.0f, 500.0f);
                spriteChicken.setPosition(1800.0f, 350.0f);
                spriteUnicorn.setPosition(1800.0f, 650.0f);
                break;
            case 4:
                spriteEBulldogs.setPosition(1800.0f, 350.0f);
                spriteFrog.setPosition(1800.0f, 650.0f);
                spritePig.setPosition(1800.0f, 500.0f);
                spriteChicken.setPosition(1800.0f, 950.0f);
                spriteUnicorn.setPosition(1800.0f, 800.0f);
                break;
            default:
                break;
            }

            relevel = false;
        }

        //Determine flight trajectory and attitude of buzz
        if (launch)
        {
            if (XBuzz <= 1920.0f && YBuzz >= 0.0f && YBuzz <= 1080.0f)
            {
                Time elapsed = clock.getElapsedTime();
                tBuzz = elapsed.asSeconds();
                float buzzvix = buzzvi * cos(angle * PI / 180.0f);
                float buzzviy = buzzvi * sin(angle * PI / 180.0f);
                float buzzvx = buzzvix;
                float buzzvy = buzzviy + tBuzz * 980.0f;
                float angleT = atan(buzzvy / buzzvx) * 180.0f / PI;
                XBuzz = 60.0f + buzzvix * tBuzz;
                YBuzz = 540.0f + buzzviy * tBuzz + 0.5f * 980.0f * powf(tBuzz, 2);
                spriteBuzz.setPosition(XBuzz, YBuzz);
                spriteBuzz.setRotation(angleT);
            }



         // the buzz is out of screen
        }
        if (XBuzz > 1920.0f || YBuzz < 0.0f || YBuzz > 1080.0f)
        {
            buzzvi = 500.0f;
            tBuzz = 0.0f;
            spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
            spriteBuzz.setRotation(0.0f);
            powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));
            rotate = true;
            power = true;
            launch = false;
            XBuzz = 0;
            YBuzz = 0;
            death.play();
            lives -= 1;
        }
        //move the insect
        if (Insectalive && path)
        {
            int a3 = placement3(generator);

            switch (a3)
            {
            case 0:
                Insectpath1 = true;
                break;
            case 1:
                Insectpath2 = true;
                break;
            case 2:
                Insectpath3 = true;
                break;
            case 3:
                Insectpath4 = true;
                break;
            case 4:
                Insectpath5 = true;
                break;
            default:
                break;
            }


            path = false;
        }
        // insect flys at random paths
        if (Insectpath1)
        {
            Time elapsed3 = Insect.getElapsedTime();
            tInsect = elapsed3.asSeconds();
            YInsecti = 50.0f;
            XInsect = XInsecti - tInsect * Insectvi;
            spriteInsect.setPosition(XInsect, YInsecti);
        }
        if (Insectpath2)
        {
            Time elapsed3 = Insect.getElapsedTime();
            tInsect = elapsed3.asSeconds();
            YInsecti = 100.0f;
            XInsect = XInsecti - tInsect * Insectvi;
            spriteInsect.setPosition(XInsect, YInsecti);
        }
        if (Insectpath3)
        {
            Time elapsed3 = Insect.getElapsedTime();
            tInsect = elapsed3.asSeconds();
            YInsecti = 150.0f;
            XInsect = XInsecti - tInsect * Insectvi;
            spriteInsect.setPosition(XInsect, YInsecti);
        }
        if (Insectpath4)
        {
            Time elapsed3 = Insect.getElapsedTime();
            tInsect = elapsed3.asSeconds();
            YInsecti = 200.0f;
            XInsect = XInsecti - tInsect * Insectvi;
            spriteInsect.setPosition(XInsect, YInsecti);
        }
        if (Insectpath5)
        {
            Time elapsed3 = Insect.getElapsedTime();
            tInsect = elapsed3.asSeconds();
            YInsecti = 250.0f;
            XInsect = XInsecti - tInsect * Insectvi;
            spriteInsect.setPosition(XInsect, YInsecti);
        }


        if (XInsect < 0.0f)
        {
            path = true;
            Insectpath1 = false;
            Insectpath2 = false;
            Insectpath3 = false;
            Insectpath4 = false;
            Insectpath5 = false;
            Insect.restart();
        }
        //set a point for buzz in order to detect collisions
        FloatRect boundingBuzz = spriteBuzz.getGlobalBounds();

        Vector2f buzzpoint = Vector2f(boundingBuzz.left +
            boundingBuzz.width / 2.0f,
            boundingBuzz.top +
            boundingBuzz.height / 2.0f);
        // collision with tiger
        FloatRect boundingTiger = spriteEtiger.getGlobalBounds();
        if (boundingTiger.contains(buzzpoint) && Tigeralive && !collisionwood)
        {
            Tigeralive = false;
            score += 25;
            buzzvi = 500.0f;
            tBuzz = 0.0f;
            spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
            spriteBuzz.setRotation(0.0f);
            powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));
            rotate = true;
            power = true;
            launch = false;
            XBuzz = 0;
            YBuzz = 0;

        }

        //collision with Bulldogs
        FloatRect boundingBulldogs = spriteEBulldogs.getGlobalBounds();
        if (boundingBulldogs.contains(buzzpoint) && Bulldogalive && !Tigeralive && !collisionwood)
        {
            Bulldogalive = false;
            score += 25;
            buzzvi = 500.0f;
            tBuzz = 0.0f;
            spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
            spriteBuzz.setRotation(0.0f);
            powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));
            rotate = true;
            power = true;
            launch = false;
            XBuzz = 0;
            YBuzz = 0;

        }


        //collision with Unicorn
        FloatRect boundingUnicorn = spriteUnicorn.getGlobalBounds();
        if (boundingUnicorn.contains(buzzpoint) && Unicornalive && !collisionwood && !Tigeralive)
        {
            Unicornalive = false;
            if (lives < 5)
            {
                lives += 1;
            }


            buzzvi = 500.0f;
            tBuzz = 0.0f;
            spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
            spriteBuzz.setRotation(0.0f);
            powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));
            rotate = true;
            power = true;
            launch = false;
            XBuzz = 0;
            YBuzz = 0;
            switch (b2)
            {
            case 0:
                spriteEBulldogs.setPosition(1800.0f, 650.0f);
                spriteFrog.setPosition(1800.0f, 500.0f);
                spritePig.setPosition(1800.0f, 800.0f);
                spriteChicken.setPosition(1800.0f, 950.0f);

                break;
            case 1:
                spriteEBulldogs.setPosition(1800.0f, 650.0f);
                spriteFrog.setPosition(1800.0f, 800.0f);
                spritePig.setPosition(1800.0f, 500.0f);
                spriteChicken.setPosition(1800.0f, 950.0f);

                break;
            case 2:
                spriteEBulldogs.setPosition(1800.0f, 950.0f);
                spriteFrog.setPosition(1800.0f, 800.0f);
                spritePig.setPosition(1800.0f, 650.0f);
                spriteChicken.setPosition(1800.0f, 500.0f);
            case 3:
                spriteEBulldogs.setPosition(1800.0f, 950.0f);
                spriteFrog.setPosition(1800.0f, 800.0f);
                spritePig.setPosition(1800.0f, 650.0f);
                spriteChicken.setPosition(1800.0f, 500.0f);

                break;
            case 4:
                spriteEBulldogs.setPosition(1800.0f, 500.0f);
                spriteFrog.setPosition(1800.0f, 800.0f);
                spritePig.setPosition(1800.0f, 650.0f);
                spriteChicken.setPosition(1800.0f, 950.0f);

                break;
            default:
                break;
            }

        }
        //collision with Insect
        FloatRect boundingInsect = spriteInsect.getGlobalBounds();
        if (boundingInsect.contains(buzzpoint) && !collisionwood)
        {
            score += 75;
            buzzvi = 500.0f;
            tBuzz = 0.0f;
            spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
            spriteBuzz.setRotation(0.0f);
            powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));
            rotate = true;
            power = true;
            launch = false;
            Insectalive = false;
        }

        //collision with wood creatures
        FloatRect boundingSheep = spriteSheep.getGlobalBounds();
        FloatRect boundingDog = spriteDog.getGlobalBounds();
        FloatRect boundingBunny = spriteBunny.getGlobalBounds();
        FloatRect boundingMouse = spriteMouse.getGlobalBounds();
        FloatRect boundingFrog = spriteFrog.getGlobalBounds();
        FloatRect boundingPig = spritePig.getGlobalBounds();
        FloatRect boundingChicken = spriteChicken.getGlobalBounds();


        if ((boundingMouse.contains(buzzpoint) || boundingBunny.contains(buzzpoint) || boundingDog.contains(buzzpoint) || boundingSheep.contains(buzzpoint)) && (!collisionwood) && (Tigeralive))
        {

            collisionwood = true;

            XBuzzi = buzzpoint.x;
            YBuzzi = buzzpoint.y;
            clock.restart();




        }

        if ((boundingPig.contains(buzzpoint) || boundingFrog.contains(buzzpoint) || boundingChicken.contains(buzzpoint)) && (!collisionwood) && (!Tigeralive))
        {

            collisionwood = true;

            XBuzzi = buzzpoint.x;
            YBuzzi = buzzpoint.y;
            clock.restart();




        }

        if (collisionwood)
        {
            float anlge1 = 0;
            Time elapsed1 = clock.getElapsedTime();
            tBuzz1 = elapsed1.asSeconds();
            anlge1 = 1000.0f * tBuzz1;
            XBuzz1 = XBuzzi;
            YBuzz1 = YBuzzi + 1000.0f * tBuzz1;

            spriteBuzz.setPosition(XBuzz1, YBuzz1);
            spriteBuzz.setRotation(anlge1);

            if (YBuzz1 > 1080.0f)
            {
                collisionwood = false;
                buzzvi = 500.0f;
                tBuzz = 0.0f;
                spriteBuzz.setPosition(60.0f, 1080 / 2.0f);
                spriteBuzz.setRotation(0.0f);
                powerBar.setSize(Vector2f(powerBarWidthperv * buzzvi, powerBarHeight));
                rotate = true;
                power = true;
                launch = false;

                XBuzz = 0;
                YBuzz = 0;
                lives -= 1;
                death.play();
            }
        }





        //recreat the level
        if (!Bulldogalive && !Tigeralive)
        {
            relevel = true;
            Bulldogalive = true;
            Tigeralive = true;
            Unicornalive = true;
            Insectalive = true;
        }
        //Game over
        if (lives == 0)
        {
            rotate = false;
            power = false;
            gameover = true;
            soundover = true;
        }
        if (soundover)
        {
            soundover = false;
            Gameover.play();

        }














        // Update the score text
        std::stringstream ss;
        ss << "Score = " << score;
        scoreText.setString(ss.str());
        scoreText1.setString(ss.str());

        window.clear();
        window.draw(spriteBackground);

        // display all sprite and texts
        if (!gameover)
        {


            if (textactive)
            {
                window.draw(messageTextname);
                window.draw(messageTextEnter);
                window.draw(messageTextEsc);
                window.draw(messageTextSpace);
                window.draw(messageTextUpdown);
                window.draw(messageTextAuthor);
            }

            window.draw(messageTextLive);
            window.draw(messageTextPower);
            window.draw(scoreText);

            window.draw(spriteBuzz);
            window.draw(powerBar);

            if (Tigeralive)
            {
                window.draw(spriteEtiger);
                window.draw(spriteSheep);
                window.draw(spriteBunny);
                window.draw(spriteDog);
                window.draw(spriteMouse);
            }

            if (Bulldogalive)
            {
                window.draw(spriteEBulldogs);
                if (Unicornalive)
                {
                    window.draw(spriteUnicorn);
                }

                window.draw(spriteFrog);
                window.draw(spritePig);
                window.draw(spriteChicken);
            }
            if (Insectalive)
            {
                window.draw(spriteInsect);
            }
            switch (lives)
            {
            case 5:
                window.draw(spriteLife1);
                window.draw(spriteLife2);
                window.draw(spriteLife3);
                window.draw(spriteLife4);
                window.draw(spriteLife5);
                break;
            case 4:
                window.draw(spriteLife1);
                window.draw(spriteLife2);
                window.draw(spriteLife3);
                window.draw(spriteLife4);
                break;
            case 3:
                window.draw(spriteLife1);
                window.draw(spriteLife2);
                window.draw(spriteLife3);
                break;
            case 2:
                window.draw(spriteLife1);
                window.draw(spriteLife2);
            case 1:
                window.draw(spriteLife1);
                break;

            default:
                break;
            }


        }
        else
        {
            window.draw(messageTextGameover);
            window.draw(scoreText1);
        }

        window.display();






    }

    return 0;
}