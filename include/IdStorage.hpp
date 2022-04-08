#ifndef ID_STORAGE_HPP
#define ID_STORAGE_HPP

#include <cstdio>
#include <unordered_map>

using id_type = size_t;

template <typename T>
class IdStorage
{
  private:
    id_type next_free_id_ {};
    std::unordered_map<id_type, T> storage_ {};

  public:
    explicit IdStorage() = default;

    IdStorage(const IdStorage&) = delete;
    IdStorage(IdStorage&) = delete;

    IdStorage& operator=(const IdStorage&) = delete;
    IdStorage& operator=(IdStorage&) = delete;

    id_type AddElement(T&& element)
    {
        id_type element_id = next_free_id_;

        assert(storage_.contains(element_id) != true);

        storage_[element_id] = std::move(element);
        ++next_free_id_;
        
        return element_id;
    }

    T& operator[](id_type id)
    {
        return storage_[id];
    }

    T& at(id_type id)
    {
        return storage_.at(id);
    }

    const T& at(id_type id) const
    {
        return storage_.at(id);
    }

    auto begin()
    {
        return storage_.begin();
    }

    const auto cbegin() const
    {
        return storage_.cbegin();
    }

    auto end()
    {
        return storage_.end();
    }

    const auto cend() const 
    {
        return storage_.cend();
    }
};

#endif /* ID_STORAGE_HPP */