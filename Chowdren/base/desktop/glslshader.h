#include "include_gl.h"
#include "fileio.h"

class FrameObject;

class BaseShader
{
public:
    static BaseShader * current;
    GLuint program;
    GLint size_uniform;
    bool initialized;
    unsigned int id;
    int flags;
    const char * texture_parameter;

    BaseShader(unsigned int id, int flags = 0,
               const char * texture_parameter = NULL);
    void initialize();
    GLuint attach_source(FSFile & fp, GLenum type);
    GLuint get_background_texture();
    int get_uniform(const char * value);
    virtual void initialize_parameters();
    void begin(FrameObject * instance, int width, int height);
    static void set_int(FrameObject * instance, int src, int uniform);
    static void set_float(FrameObject * instance, int src, int uniform);
    static void set_vec4(FrameObject * instance, int src, int uniform);
    static void set_image(FrameObject * instance, int src);
};


