#ifndef _IM_SCENEINDEX_H
#define _IM_SCENEINDEX_H

#include "../imKeyList.h"
#include "../surface/imTexture.h"
#include "../surface/imMaterial.h"
#include "imEnvironment.h"
#include "../sound/imSoundSource.h"

class imSceneIndex {
public:
    imSceneIndex()
    { }

    ~imSceneIndex()
    { }

    bool read(imStream* stream);

    imRef<imTexture> texture(unsigned int id)
    {
        if (id < m_textures.size())
            return m_textures[id];
        return 0;
    }

    imRef<imMaterial> material(unsigned int id)
    {
        if (id < m_materials.size())
            return m_materials[id];
        return 0;
    }

private:
    imString m_name;
    imString m_page;
    std::vector<imString> m_sceneRefs;
    std::vector<imString> m_keyRefs;
    std::vector<imRef<imTexture> > m_textures;
    std::vector<imRef<imMaterial> > m_materials;
    imEnvironment m_environment;
    std::vector<imRef<imSoundSource> > m_sounds;
};

#endif