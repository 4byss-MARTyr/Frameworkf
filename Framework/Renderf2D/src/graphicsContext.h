#pragma once

#include <memory>

#include "Platform/window.h"
#include "Shader/shaderProgram.h"
#include "Buffer/buffer.h"

namespace Ff
{
    enum class RenderAPI
    {
        OpenGL,
        None,
    };

    struct Viewport2D
    {
        float x{};
        float y{};
        float width{1}; 
        float height{1};
        float mindepth{};
        float maxdepth{1};
    };

    extern RenderAPI gRenderAPI;

    class GraphicsContext
    {
    public:
        GraphicsContext(Window* window)
            : m_window(window)
        {
        }

        virtual ~GraphicsContext() = default;
        static std::unique_ptr<GraphicsContext> create(Window* window);

        virtual void useProgram(std::shared_ptr<ShaderProgram> program) = 0;
        
        virtual void bindVertexBuffer(std::shared_ptr<VertexBuffer> buffer) = 0;

        virtual void draw(uint32_t vertexCount) = 0;

        virtual void setViewport(Viewport2D viewport) = 0;

    protected:
        Window* m_window;
    };
} // namespace Ff