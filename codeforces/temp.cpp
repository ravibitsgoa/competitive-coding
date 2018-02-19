#include "TextureManager.hpp"

inferno::graphics::TextureManager::Load(std::string texture_filename,
                                        std::string texture_name) {

    TextureHandle handle = make_shared<Texture>(texture_filename, texture_name);

    if(handle == nullptr) {
        throw std::runtime_error("Invalid texture_filename: "+texture_filename);
    }

    this->textures.insert({handle->GetHash(), handle});
}

void inferno::graphics::TextureManager::LoadAll(
    std::vector<std::string> texture_filenames,
    std::vector<std::string> texture_names) {

    if(texture_filenames.size() != texture_name.size()) {
        throw std::runtime_error("Number of filenames and "+
        "number of names of textures must be same.");
    }

    for(size_t i=0; i<texture_filenames.size(); i++) {
        this->Load(texture_filenames.at(i), texture_name.at(i));
    }
}

void inferno::graphics::TextureManager::Remove(std::string texture_name) {

    this->textures.erase(std::hash<std::string>(texture_name));
}

void inferno::graphics::TextureManager::RemoveAll(std::string texture_name) {
    this->textures.clear();
}

TextureHandle inferno::graphics::TextureManager::Get(std::string texture_name) const {
    auto iterator = this->textures.find(std::hash<std::string>(texture_name));
    if(iterator == this->textures.end()) {
        throw std::runtime_error("No such texture with name "+ texture_name);
    }
    return iterator->second;
}

TextureHandle operator[](std::string texture_name) const {
    return this->Get(texture_name);
}
