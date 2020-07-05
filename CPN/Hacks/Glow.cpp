#include "../_Objects/Objects.hpp"

#include <thread>
#include "Glow.h"
#include "../Config/Config.h"



void Glow::render() noexcept {
    if (!config->GlowAlies.enabled && !config->GlowEnemy.enabled) {
        return;
    }

    if (EngineOld::InGame())
    {
        for (int i = 0; i < 32; i++)
        {
            if (EntityOld(i).Base() == NULL) continue;
            if (EntityOld(i).Dormant()) continue;

            if (EntityOld(i).Team() == LocalPlayerOld::Team())
            {
                // Teammate
                if (config->GlowAlies.enabled)
                {
                    GlowObjectDefinition glowObject = EntityOld(i).GlowObject();

                    if (config->GlowHealth_Team)
                    { // Health based
                        glowObject.r = (255.f - EntityOld(i).Health() * 2.55f) / 255.f;
                        glowObject.g = (EntityOld(i).Health() * 2.55f) / 255.f;
                        glowObject.b = 0.f;
                    }
                    else
                    {
                        glowObject.r = config->GlowAlies.color[0];
                        glowObject.g = config->GlowAlies.color[1];
                        glowObject.b = config->GlowAlies.color[2];
                    }

                    glowObject.m_flGlowAlpha = config->GlowAlies.color[3] * 2.f;

                    glowObject.m_bFullBloomRender = config->FullBloomTeam;
                    glowObject.m_nGlowStyle = config->GlowOnly_Team ? 1 : 0;
                    glowObject.m_bRenderWhenOccluded = true;
                    glowObject.m_bRenderWhenUnoccluded = false;

                    EntityOld(i).GlowObject(glowObject);      
                }
            }
            else
            {
                // Enemy
                if (config->GlowEnemy.enabled)
                {
                    GlowObjectDefinition glowObject = EntityOld(i).GlowObject();

                    if (config->GlowHealth_Enemy)
                    { // Health based
                        glowObject.r = (255.f - EntityOld(i).Health() * 2.55f) / 255.f;
                        glowObject.g = (EntityOld(i).Health() * 2.55f) / 255.f;
                        glowObject.b = 0.f;
                    }
                    else
                    {
                        glowObject.r = config->GlowEnemy.color[0];
                        glowObject.g = config->GlowEnemy.color[1];
                        glowObject.b = config->GlowEnemy.color[2];
                    }

                    glowObject.m_flGlowAlpha = config->GlowEnemy.color[3] * 2.f;

                    glowObject.m_bFullBloomRender = config->FullBloomEnemy;
                    glowObject.m_nGlowStyle = config->GlowOnly_Enemy ? 1 : 0;
                    glowObject.m_bRenderWhenOccluded = true;
                    glowObject.m_bRenderWhenUnoccluded = false;

                    EntityOld(i).GlowObject(glowObject);
                }
            }
        }
    }
    else {
        return;
    }
};