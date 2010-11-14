/* Python-specific extensions of classes for more convenient/readable code. */
%include "../shared.i"

%extend lite::ITextureLib {
    lite::ITexture* get(const string& filename)
    {
        return (*$self)[filename];
    }
};

%extend lite::EdgeArray {
    lite::Edge __getitem__(int number)
    {
        return (*$self)[number];
    }
}

%extend lite::TextureGrid {
    const lite::ITexture& __getitem__(int number)
    {
        return *(*$self)[number];
    }
}

%extend Vector2 {
    const Vector2 __add__(const Vector2& other)
    {
        return *($self) + other;
    }

    const Vector2 __sub__(const Vector2& other)
    {
        return *($self) - other;
    }

    const Vector2 __mul__(double scalar)
    {
        return *($self) * scalar;
    }

    const Vector2 __div__(double scalar)
    {
        return *($self) / scalar;
    }
}
