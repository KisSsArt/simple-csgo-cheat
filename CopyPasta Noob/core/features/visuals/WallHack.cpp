#include "../features.hpp"
#include "../../../hazedumper.hpp"
#include "../../../_Objects/Objects.hpp"

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
                if (variables::TeamGlow_bool) {
                    if (variables::GlowHealth_Team) { // Health based
                        Entity(i).GlowObject((255.f - Entity(i).Health() * 2.55f) / 255.f, (Entity(i).Health() * 2.55f) / 255.f, 0, variables::Brightness_Team, false);
                    }
                    else
                    {
                        Entity(i).GlowObject(variables::TeamColorR / 255.f, variables::TeamColorG / 255.f, variables::TeamColorB / 255.f, variables::Brightness_Team, false);
                    }
                }
            }
            else
            {
                // Enemy
                if (variables::EnemyGlow_bool) {
                    if (variables::GlowHealth_Enemy) { // Health based
                        Entity(i).GlowObject((255.f - Entity(i).Health() * 2.55f) / 255.f, (Entity(i).Health() * 2.55f) / 255.f, 0, variables::Brightness_Enemy, false);
                    }
                    else
                    {
                        Entity(i).GlowObject(variables::EnemyColorR / 255.f, variables::EnemyColorG / 255.f, variables::EnemyColorB / 255.f, variables::Brightness_Enemy, false);
                    }
                }
            }
            Entity(i).RenderWhenOccluded(true);
            Entity(i).RenderWhenUnoccluded(false);
        }
    }
};