#ifndef ADD_DRAW_SUBSCRIPTION_HPP
#define ADD_DRAW_SUBSCRIPTION_HPP

#include "ObjectStorage.hpp"
#include "UsingAliasMolecularBox.hpp"
#include "IdStorage.hpp"
#include "Interaction.hpp"
#include "DrawObject.hpp"

#include "GetGraphic.hpp"

class AddDrawSubscription
{
  private:
    const ObjectStorage& objects_;
    IdStorage<Interaction>& interactions_;
    const molecular_box_coordinate_system& coordinate_system_;

    const time_type& current_time_;
    time_type& next_drawning_time_;
    const time_type drawning_period_;

  public:
    AddDrawSubscription() = delete;
    AddDrawSubscription(const ObjectStorage& objects, IdStorage<Interaction>& interactions, const molecular_box_coordinate_system& coordinate_system, 
                        const time_type& current_time, time_type& next_drawning_time, const time_type drawning_period);

    void operator()(id_type id);
};

std::function<void()> GetDrawAction(const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, 
                                    time_type& next_drawning_time, const time_type drawning_period, id_type id);
std::function<bool()> GetDrawCheck(const time_type& current_time, time_type& next_drawning_time, const time_type drawning_period);

#endif /* ADD_DRAW_SUBSCRIPTION_HPP */
