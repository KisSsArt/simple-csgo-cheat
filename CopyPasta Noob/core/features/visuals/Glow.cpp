#include "../features.hpp"
#include "../../../hazedumper.hpp"
#include "../../../_Objects/Objects.hpp"

#include <vector>
void visuals::wh::glow(c_usercmd* cmd) {
    if (!variables::Glow_bool) {
        return;
    }

    if (Engine::InGame())
    {
        for (int i = 0; i < 32; i++)
        {     
            if (Entity(i).Base() == NULL) continue;
            if (Entity(i).Dormant()) continue;

            if (Entity(i).Team() == LocalPlayer::Team())
            {
                // Teammate
                if (variables::TeamGlow_bool)
                {
                    GlowObjectDefinition glowObject = Entity(i).GlowObject();

                    if (variables::GlowHealth_Team) 
                    { // Health based
                        glowObject.r = (255.f - Entity(i).Health() * 2.55f) / 255.f;
                        glowObject.g = (Entity(i).Health() * 2.55f) / 255.f;
                        glowObject.b = 0.f;
                    }
                    else 
                    {
                        glowObject.r = variables::TeamColorR / 255.f;
                        glowObject.g = variables::TeamColorG / 255.f;
                        glowObject.b = variables::TeamColorB / 255.f;
                    }

                    glowObject.m_flGlowAlpha = variables::Brightness_Team;

                    glowObject.m_bFullBloomRender = variables::FullBloomTeam;
                    glowObject.m_nGlowStyle = variables::GlowOnly_Team ? 1 : 0;
                    glowObject.m_bRenderWhenOccluded = true;
                    glowObject.m_bRenderWhenUnoccluded = false;

                    Entity(i).GlowObject(glowObject);
                }
            }
            else
            {
                // Enemy
                if (variables::EnemyGlow_bool) 
                {
                    GlowObjectDefinition glowObject = Entity(i).GlowObject();

                    if (variables::GlowHealth_Enemy) 
                    { // Health based
                        glowObject.r = (255.f - Entity(i).Health() * 2.55f) / 255.f;
                        glowObject.g = (Entity(i).Health() * 2.55f) / 255.f;
                        glowObject.b = 0.f;
                    }
                    else 
                    {
                        glowObject.r = variables::EnemyColorR / 255.f;
                        glowObject.g = variables::EnemyColorG / 255.f;
                        glowObject.b = variables::EnemyColorB / 255.f;
                    }

                    glowObject.m_flGlowAlpha = variables::Brightness_Enemy;

                    glowObject.m_bFullBloomRender = variables::FullBloomEnemy;
                    glowObject.m_nGlowStyle = variables::GlowOnly_Enemy ? 1 : 0;
                    glowObject.m_bRenderWhenOccluded = true;
                    glowObject.m_bRenderWhenUnoccluded = false;

                    Entity(i).GlowObject(glowObject);
                }
            }
        }
    }
};