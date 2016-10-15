
#ifndef ANALIZARNOTICIASLINUX_PATHUTILS_H
#define ANALIZARNOTICIASLINUX_PATHUTILS_H

#include <string>
#include <vector>
#include <glob.h>
#include <sys/stat.h>


inline std::vector<std::string> globVector(const std::string& pattern){
    glob_t glob_result;
    glob(pattern.c_str(),GLOB_TILDE,NULL,&glob_result);
    std::vector<std::string> files;
    for(unsigned int i=0;i<glob_result.gl_pathc;++i){
        files.push_back(std::string(glob_result.gl_pathv[i]));
    }
    globfree(&glob_result);
    return files;
}

inline bool fileExists (const std::string& filePath) {
    struct stat buffer;
    return (stat (filePath.c_str(), &buffer) == 0);
}


#endif //ANALIZARNOTICIASLINUX_PATHUTILS_H
