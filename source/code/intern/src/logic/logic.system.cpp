#include "logic.system.h"

#include <iostream>

#include "../data/data.entitySystem.h"
#include "../data/data.entityCategory.h"
#include "../data/data.playerSystem.h"
#include "../data/data.pointSystem.h"
#include "../data/data.eventSystem.h"

#include "../game/game.playPhase.h"

#include "logic.command.h"
#include "logic.commandSystem.h"

namespace Logic
{
    void System::OnTurn()
    {
        HandleCommands();
    }

    void System::HandleCommands()
    {
        CommandSystem& commandSystem = CommandSystem::GetInstance();
        Command* currentCommand;

        while (commandSystem.HasCommands())
        {
            currentCommand = &(commandSystem.GetNextCommand());

            switch (currentCommand->GetType())
            {
                case Data::CommandType::CommandAction::MoveUp:
                    MovePlayer(Core::Float2(0.0f, -64.0f));
                    break;
                case Data::CommandType::CommandAction::MoveDown:
                    MovePlayer(Core::Float2(0.0f, 64.0f));
                    break;
                case Data::CommandType::CommandAction::MoveRight:
                    MovePlayer(Core::Float2(64.0f, 0.0f));
                    break;
                case Data::CommandType::CommandAction::MoveLeft:
                    MovePlayer(Core::Float2(-64.0f, 0.0f));
                    break;
                default:
                    break;
            }

            commandSystem.RemoveNextCommand();
        }
    }

    void System::MovePlayer(Core::Float2 orientation)
    {
        Data::PlayerSystem& playerSystem = Data::PlayerSystem::GetInstance();
        Data::Entity* player = playerSystem.GetPlayer();
        if (player != nullptr)
        {
            // TODO: This needs to replaced with the proper EntityMap System call with the new aabb after the move (massive performance increase)
            // because we would not have to run through all entities again but just the ones within the aabb + 1px in each direction
            std::vector<Data::Entity*> entities = Data::EntitySystem::GetInstance().GetAllEntities();
            std::vector<Data::Entity*> collisionEntities;

            bool playerCollidedWithFinish = false;
            std::vector<Data::Entity*> collectedCoins = std::vector<Data::Entity*>();

            for (Data::Entity* entity : entities)
            {
                if (entity != nullptr)
                {
                    if (Core::CAABB3<float>(
                        Core::Float3(player->position[0] + orientation[0] + 1, player->position[1] + orientation[1] + 1, player->position[2]),
                        Core::Float3(player->position[0] + orientation[0] + 63, player->position[1] + orientation[1] + 63, player->position[2])
                    ).Intersects(entity->aabb))
                    {
                        if (entity->category == Data::EntityCategory::Ground)
                        {
                            collisionEntities.push_back(entity);
                        }

                        if (entity->category == Data::EntityCategory::Coin)
                        {
                            collectedCoins.push_back(entity);
                        }

                        if (entity->category == Data::EntityCategory::Finish)
                        {
                            playerCollidedWithFinish = true;

                            Data::EventSystem::GetInstance().FireEvent(Data::EventType::FINISH_MAP);
                        }
                    }
                }
            }

            if (collisionEntities.empty())
            {
                // If not collisions occure with walls we move the player
                player->position = Core::Float3(player->position[0] + orientation[0], player->position[1] + orientation[1], player->position[2]);
                player->aabb = Core::CAABB3<float>(
                    Core::Float3(player->position[0], player->position[1], player->position[2]),
                    Core::Float3(player->position[0] + 64, player->position[1] + 64, player->position[2])
                );

                // Only if the player actually moved we add the collected coin(s) to the score and remove them from the map
                for (Data::Entity* entity : collectedCoins)
                {
                    Data::PointSystem::GetInstance().AddPoints(1);
                    Data::EntitySystem::GetInstance().DestroyEntity(*entity);
                }
            } else
            {
                // Collided with a wall, so don't move the player
            }
        }
    }
}
