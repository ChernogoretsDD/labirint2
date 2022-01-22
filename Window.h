#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <GL/gl.h>
#include <GL/glu.h>


class Window
{
    public:
        // Размеры по-умолчанию
        static constexpr int DEFAULT_WIDTH = 1920;
        static constexpr int DEFAULT_HEIGHT = 1080;
        
    protected:
        // Указатель на окно SDL
        std::shared_ptr<SDL_Window> _window;
        // Указатель на контекст OpenGL
        std::shared_ptr<void> _gl_context;

        // Ширина и высота окна
        int _width, _height;
    public:
        
        // Конструктор класса Window
        Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
        
        // Деструктор класса Window
        virtual ~Window() = default;

        // получение ширины/высоты окна
        int width() const {
            return _width; 
        }
        int height() const {
            return _height;
            
        }
        
        void main_loop();
        virtual void setup() { }
        virtual void render() { }
        virtual void handle_event(SDL_Event &event) { }
        virtual void handle_keys(const Uint8 * keys) { }
        virtual void handle_logic() { }
};


#endif /* WINDOW_H_ */
