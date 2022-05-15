#include <InteractionStorage.hpp>

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
        interaction.TryAction();
    }

    for (auto& [id, predictable_interaction]: predictable_interactions_)
    {
        predictable_interaction.TryAction();
    }

    drawning_interaction_.TryAction();
}