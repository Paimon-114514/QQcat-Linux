#include "SystemFunc.hpp"

/**
 * @brief Recursively search all files under a directory and get their full paths
 * @param root_dir Root directory path
 * @param file_paths JSON array to store file paths (output parameter)
 */
void recursiveSearchFiles(const string& root_dir, json& file_paths) {
    DIR* dir = opendir(root_dir.c_str());
    if (dir == nullptr) {
        cerr << "Error: Failed to open directory " << root_dir << "!" << endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        // Skip current directory (.) and parent directory (..)
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full path
        string full_path;
        if (root_dir == "." || root_dir.back() == '/') {
            full_path = root_dir + entry->d_name;
        } else {
            full_path = root_dir + "/" + entry->d_name;
        }

        // Check if it's a directory or a file
        struct stat statbuf;
        if (stat(full_path.c_str(), &statbuf) == -1) {
            cerr << "Error: Failed to get stat for " << full_path << "!" << endl;
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // It's a directory, recursively search it
            recursiveSearchFiles(full_path, file_paths);
        } else if (S_ISREG(statbuf.st_mode)) {
            // It's a regular file, add to JSON array
            file_paths.push_back(full_path);
        }
    }

    closedir(dir);
}

int main() {
    // Target root directory (can be modified as needed)
    const string root_dir = "../";
    
    // Initialize JSON array to store all file paths
    json file_paths_json = json::array();

    // Perform recursive search
    recursiveSearchFiles(root_dir, file_paths_json);

    // Output JSON result (formatted output for readability)
    cout << "=== All File Paths (JSON Format) ===" << endl;
    cout << file_paths_json.dump(4) << endl;

    // Optional: Write JSON result to file
    ofstream json_file("file_paths.json");
    if (json_file.is_open()) {
        json_file << file_paths_json.dump(4);
        json_file.close();
        cout << "\nJSON result has been written to file_paths.json" << endl;
    } else {
        cerr << "\nError: Failed to write to file_paths.json!" << endl;
    }

    return 0;
}