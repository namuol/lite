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
