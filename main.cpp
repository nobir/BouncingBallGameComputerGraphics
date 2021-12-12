#include "helper.hh"
#include "Page/GameKeyboardShortcutPage.hh"
#include "Page/GameOverPage.hh"
#include "Page/GameCoverPage.hh"
#include "Page/GameMenuPage.hh"
#include "Page/GameSettingsPage.hh"
#include "Page/GamePage.hh"

void display()
{
    glClearColor(34 / 255.0f, 47 / 255.0f, 62 / 255.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (is_menu_page)
    {
        gameMenuPage();
    }
    else if (is_cover_page)
    {
        gameCoverPage();
    }
    else if (is_settings_page)
    {
        gameSettingsPage();
    }
    else if (is_game_over)
    {
        gameOverPage();
    }
    else if (is_keyBoard_shortcut_page)
    {
        gameKeyboarShortcut();
    }
    else if (is_game_page)
    {
        gamePage();
    }
}

// Reset game or initialize the game
void initializeGame()
{
    life = 3;
    point = 0;
    _collision = 0;

    is_started = GL_FALSE;
    is_collision = GL_FALSE;
    is_new_game = GL_FALSE;

    if (is_sound)
    {
        is_sound = GL_TRUE;
    }

    is_menu_page = GL_TRUE;
    is_game_page = GL_FALSE;
    is_cover_page = GL_FALSE;
    is_settings_page = GL_FALSE;
    is_game_over = GL_FALSE;
    is_keyBoard_shortcut_page = GL_FALSE;

    easy_mode = GL_FALSE;
    medium_mode = GL_FALSE;
    hard_mode = GL_FALSE;

    current_mode = 0;

    // Ball 1
    ball1.positionY = -(height - (ball1.getSizeY() + 5.0f + 2.0f * barX1.getSizeY())); // For Down
    // ball1.positionY = (height - (ball1.getSizeY() + 2.0f * barX1.getSizeY()));      // For Up
    ball1.positionX = 0.0f;

    ball1.moveX = GL_FALSE;
    ball1.moveY = GL_FALSE;

    // Bar X 1
    barX1.positionY = (height - barX1.getSizeY());
    barX1.positionX = 0.0f;
    barX1.move_left = GL_FALSE;
    barX1.move_right = GL_FALSE;
    barX1.move_up = GL_FALSE;
    barX1.move_down = GL_FALSE;

    // Bar X 2
    barX2.positionY = -(height - barX2.getSizeY());
    barX2.positionX = 0.0f;
    barX2.move_left = GL_FALSE;
    barX2.move_right = GL_FALSE;
    barX2.move_up = GL_FALSE;
    barX2.move_down = GL_FALSE;

    // Bar Y 1
    barY1.positionX = (width - barY1.getSizeX());
    barY1.positionY = 0.0f;
    barY1.move_left = GL_FALSE;
    barY1.move_right = GL_FALSE;
    barY1.move_up = GL_FALSE;
    barY1.move_down = GL_FALSE;

    // Bar Y 2
    barY2.positionX = -(width - barY2.getSizeX());
    barY2.positionY = 0.0f;
    barY2.move_left = GL_FALSE;
    barY2.move_right = GL_FALSE;
    barY2.move_up = GL_FALSE;
    barY2.move_down = GL_FALSE;

    if (is_sound)
    {
        PlaySound(TEXT("audio/music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else
    {
        PlaySound(NULL, NULL, SND_ASYNC);
    }
}

void update(int frame_rate)
{
    if (!is_started)
        return;

    barMovement();

    ballMovement();

    glutTimerFunc(frame_rate, update, frame_rate);
}

void specialKeyboardDown(int key, int x, int y)
{
    if (!is_started)
        return;

    switch (key)
    {
    case GLUT_KEY_LEFT:

        barX1.move_left = GL_TRUE;
        barX2.move_left = GL_TRUE;

        break;
    case GLUT_KEY_RIGHT:

        barX1.move_right = GL_TRUE;
        barX2.move_right = GL_TRUE;

        break;
    case GLUT_KEY_UP:

        barY1.move_up = GL_TRUE;
        barY2.move_up = GL_TRUE;

        break;
    case GLUT_KEY_DOWN:

        barY1.move_down = GL_TRUE;
        barY2.move_down = GL_TRUE;

        break;
    default:
        break;
    }
}

void specialKeyboardUp(int key, int x, int y)
{
    if (!is_started)
        return;

    switch (key)
    {
    case GLUT_KEY_LEFT:

        barX1.move_left = GL_FALSE;
        barX2.move_left = GL_FALSE;

        break;
    case GLUT_KEY_RIGHT:

        barX1.move_right = GL_FALSE;
        barX2.move_right = GL_FALSE;

    case GLUT_KEY_UP:

        barY1.move_up = GL_FALSE;
        barY2.move_up = GL_FALSE;

        break;
    case GLUT_KEY_DOWN:

        barY1.move_down = GL_FALSE;
        barY2.move_down = GL_FALSE;

        break;
    default:
        break;
    }
}

void setFrameRate(int frame_rate)
{
    if (cfr != frame_rate)
        return;

    glutPostRedisplay();
    glutTimerFunc(frame_rate, setFrameRate, frame_rate);
}

void keyboardDown(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '0':

        // Set the frame rate 15
        if (cfr == frame_rate_15)
            break;

        cfr = frame_rate_15;
        setFrameRate(frame_rate_15);

        break;
    case '1':

        // Set the frame rate 30
        if (cfr == frame_rate_30)
            break;

        cfr = frame_rate_30;
        setFrameRate(frame_rate_30);

        break;
    case '2':

        // Set the frame rate 60
        if (cfr == frame_rate_60)
            break;

        cfr = frame_rate_60;
        setFrameRate(frame_rate_60);

        break;
    case '3':

        // Set the frame rate 120
        if (cfr == frame_rate_120)
            break;

        cfr = frame_rate_120;
        setFrameRate(frame_rate_120);

        break;
    case '4':

        // Set the frame rate 144
        if (cfr == frame_rate_144)
            break;

        cfr = frame_rate_144;
        setFrameRate(frame_rate_144);

        break;
    case 27: // Esc

        // Show Menu page
        if (is_menu_page || is_game_over)
        {
            break;
        }

        if (is_started)
        {
            is_started = GL_FALSE;
        }

        is_menu_page = GL_TRUE;

        is_game_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        break;
    case 'k':

        // Show Keyboard Shorcut page
        if (is_keyBoard_shortcut_page || is_game_over)
        {
            break;
        }

        if (is_started)
        {
            is_started = GL_FALSE;
        }

        is_keyBoard_shortcut_page = GL_TRUE;

        is_menu_page = GL_FALSE;
        is_game_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;

        break;
    case 'l':

        // Show Menu page from keyboard shortcut page
        if (!is_keyBoard_shortcut_page || is_game_over)
        {
            break;
        }

        is_menu_page = GL_TRUE;

        is_game_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        break;
    case 'c':

        // Show cover page
        if (is_cover_page || is_game_over)
        {
            break;
        }

        if (is_started)
        {
            is_started = GL_FALSE;
        }

        is_cover_page = GL_TRUE;

        is_menu_page = GL_FALSE;
        is_game_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        break;
    case 'x':

        // Show Settings
        if (is_settings_page || is_game_over)
        {
            break;
        }

        if (is_started)
        {
            is_started = GL_FALSE;
        }

        is_settings_page = GL_TRUE;

        is_menu_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_game_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        break;
    case 's':

        // Start the game
        if (is_started || is_game_over || is_menu_page || is_settings_page || is_cover_page || is_keyBoard_shortcut_page)
        {
            break;
        }

        if (is_game_page)
        {
            is_started = GL_TRUE;
            update(frame_rate_144);
        }

        break;
    case 'p':

        // Pause the game
        if (is_started)
        {
            is_started = GL_FALSE;
        }

        break;
    case 'r':

        // Resume the game
        if (current_mode == 0)
            break;

        is_game_page = GL_TRUE;

        is_menu_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        PlaySound(NULL, NULL, SND_ASYNC);

        break;
    case 'n':

        // New game
        if (is_new_game)
            break;

        initializeGame();

        is_new_game = GL_TRUE;
        is_menu_page = GL_TRUE;

        is_game_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        ball1.rgbaColor = {255, 121, 63, 255};

        break;
    case 'e':

        // Easy game mode
        if (easy_mode || medium_mode || hard_mode)
            break;

        initializeGame();

        is_game_page = GL_TRUE;
        easy_mode = GL_TRUE;
        current_mode = 1;

        medium_mode = GL_FALSE;
        hard_mode = GL_FALSE;

        is_menu_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        ball1.speed = 2.0f;
        ball1.rgbaColor = {255, 121, 63, 255};

        PlaySound(NULL, NULL, SND_ASYNC);

        break;
    case 'm':

        // Medium game mode
        if (easy_mode || medium_mode || hard_mode)
            break;

        initializeGame();

        is_game_page = GL_TRUE;
        medium_mode = GL_TRUE;
        current_mode = 2;

        easy_mode = GL_FALSE;
        hard_mode = GL_FALSE;

        is_menu_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        ball1.speed = 1.0f;
        ball1.rgbaColor = {255, 121, 63, 255};

        PlaySound(NULL, NULL, SND_ASYNC);

        break;
    case 'h':

        // Hard game mode
        if (easy_mode || medium_mode || hard_mode)
            break;

        initializeGame();

        is_game_page = GL_TRUE;
        hard_mode = GL_TRUE;
        current_mode = 3;

        medium_mode = GL_FALSE;
        easy_mode = GL_FALSE;

        is_menu_page = GL_FALSE;
        is_cover_page = GL_FALSE;
        is_settings_page = GL_FALSE;
        is_game_over = GL_FALSE;
        is_keyBoard_shortcut_page = GL_FALSE;

        ball1.speed = 2.5f;
        ball_opacity_hard_mode = 255;

        PlaySound(NULL, NULL, SND_ASYNC);

        break;
    case '8':

        // Sound on
        if (is_settings_page)
        {
            is_sound = GL_TRUE;
            PlaySound(TEXT("audio/music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }

        break;
    case '9':

        // Sound off
        if (is_settings_page)
        {
            is_sound = GL_FALSE;
            PlaySound(NULL, NULL, SND_ASYNC);
        }

        break;
    case 'q':

        // Quit the game
        if (is_game_over || is_menu_page)
        {
            glutDestroyWindow(glutGetWindow());
        }

        break;
    default:
        return;
    }
}

void initGlut()
{
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    // glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_LINE_SMOOTH);
    // glEnable(GL_POLYGON_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((width + gutter) * -1.0f, (width + gutter) * 1.0f, (height + gutter) * -1.0f, (height + gutter) * 1.0f);
}

int main(int argc, char **argv)
{
    // optimize();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutInitWindowSize(width + gutter, height + gutter);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - (width + gutter)) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - (height + gutter)) / 2);
    glutCreateWindow("Bouncing Ball");

    glutFullScreen();

    glutKeyboardFunc(keyboardDown);

    glutSpecialFunc(specialKeyboardDown);
    glutSpecialUpFunc(specialKeyboardUp);

    glutDisplayFunc(display);

    initGlut();

    setFrameRate(cfr);

    PlaySound(TEXT("audio/music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    glutMainLoop();

    return 0;
}
