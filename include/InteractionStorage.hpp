#ifndef INTERACTION_STORAGE_HPP
#define INTERACTION_STORAGE_HPP

#include "Interaction.hpp"
#include "DrawningInteraction.hpp"

class InteractionStorage
{
  private:
    IdStorage<Interaction> interactions_;
    IdStorage<PredictableInteraction> predictable_interactions_;
    DrawningInteraction drawning_interaction_;

  public:
    InteractionStorage() = delete;

    template<typename GraphicImplementation>
    InteractionStorage(const time_type& global_time, const time_type next_drawning_time, const time_type drawning_period,
                       const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, 
                       const color background_color, GraphicInterface<GraphicImplementation>* graphic):
        drawning_interaction_(global_time, next_drawning_time, drawning_period, objects, coordinate_system, background_color, graphic)
    {
    }

    void AddInteraction(Interaction&& interaction);
    void AddPredictableInteraction(PredictableInteraction&& predictable_interaction);
    void AddObjectToDraw(id_type id);

    void TryDraw();
    void CheckInteractions();
};

#endif /* INTERACTION_STORAGE_HPP */
