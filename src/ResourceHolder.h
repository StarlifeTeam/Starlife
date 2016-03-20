#ifndef SL_RESOURCE_HOLDER_H
#define SL_RESOURCE_HOLDER_H

#include <cassert>
#include <memory>
#include <utility>
#include <string>
#include <map>

/*Class definition of the resource holder*/
template <typename Resource, typename Identifier>
class ResourceHolder{
public:
  //Load a resource
  void load(Identifier, const std::string);
  //Load a resource whit 2 params
  template <typename Parameter>
  void load(Identifier, const std::string, const Parameter&);
  //Get a resource
  Resource& get(Identifier);
  //Get a const resource
  const Resource& get(Identifier) const;
private:
  //Insert a resource in the internal map
  void insert(Identifier, std::unique_ptr<Resource>);
protected:
  //Internal resource map
  std::map<Identifier, std::unique_ptr<Resource> > resourceMap;
};

/*Methods */

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string path){
  std::unique_ptr<Resource> resource(new Resource());
  if(!resource->loadFromFile(path)){
    throw std::runtime_error("ResourceHolder: Unable to load the resource " + path);
  }
  this->insert(id, std::move(resource));
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string path, const Parameter& secondParam){
  std::unique_ptr<Resource> resource(new Resource());
  if(!resource->loadFromFile(path, secondParam)){
    throw std::runtime_error("ResourceHolder: Unable to load the resource " + path);
  }
  this->insert(id, std::move(resource));
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id){
  auto found = resourceMap.find(id);
  assert(found != resourceMap.end());
  return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const{
  auto found = resourceMap.find(id);
  assert(found != resourceMap.end());
  return *found->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insert(Identifier id, std::unique_ptr<Resource> ptr){
  auto inserted = resourceMap.insert(std::make_pair(id, std::move(ptr)));
  assert(inserted.second);
}

#endif