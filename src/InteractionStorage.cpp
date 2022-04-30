#include <InteractionStorage.hpp>

InteractionStorage::InteractionStorage(const time_type& global_time, const time_type next_drawning_time, const time_type drawning_period,
                                       const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, 
                                       const color background_color) :
    drawning_interaction_(global_time, next_drawning_time, drawning_period, objects, coordinate_system, background_color)
{
}

void InteractionStorage::AddInteraction(Interaction&& interaction)
{
    interactions_.AddElement(std::move(interaction));
}

void InteractionStorage::AddPredictableInteraction(PredictableInteraction&& predictable_interaction)
{
    predictable_interactions_.AddElement(std::move(predictable_interaction));
}

void InteractionStorage::AddObjectToDraw(id_type id)
{
    drawning_interaction_.AddObjectToDraw(id);
}

void InteractionStorage::CheckInteractions()
{
    for (auto& [id, interaction]: interactions_)
    {
        if (interaction.CheckConditionForAction() == true)
        {
            interaction.Action();
        }
    }

    for (auto& [id, predictable_interaction]: predictable_interactions_)
    {
        if (predictable_interaction.CheckConditionForAction() == true)
        {
            predictable_interaction.Action();
        }
    }

    if (drawning_interaction_.CheckConditionForAction() == true)
    {
        drawning_interaction_.Action();
    }
}