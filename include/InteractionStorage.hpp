#ifndef INTERACTION_STORAGE_HPP
#define INTERACTION_STORAGE_HPP

#include "Interaction.hpp"
#include "DrawningInteraction.hpp"

class InteractionStorage
{
  private:
    IdStorage<Interaction> interactions_;
    IdStorage<PredictableInteraction> predictable_interactions_;
    DrawningInteraction::DrawningInteraction drawning_interaction_;

  public:
    InteractionStorage() = delete;

    template<typename GraphicImplementation, typename TimerImplementation>
    InteractionStorage(const DrawningInteraction::time_info time_info, const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system,
                       const color background_color, const milliseconds delay, 
                       DrawningInteraction::drawning_adapters<GraphicImplementation, TimerImplementation> adapters):
        drawning_interaction_(time_info, objects, coordinate_system, background_color, delay, adapters)
    {
    }

    void AddInteraction(Interaction&& interaction);
    void AddPredictableInteraction(PredictableInteraction&& predictable_interaction);
    void AddObjectToDraw(id_type id);

    void TryDraw();
    void CheckInteractions();
};

#endif /* INTERACTION_STORAGE_HPP */
