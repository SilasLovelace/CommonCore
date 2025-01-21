/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:45 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/21 14:50:22 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

void replaceStringInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Could not open the file '" << filename << "'." << "\n";
        return;
    }
    std::string outputFilename = filename + ".replace";
    std::ostringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContent = buffer.str();
    inputFile.close();
    
    std::string result;
    size_t pos = 0, prevPos = 0;

    while ((pos = fileContent.find(s1, prevPos)) != std::string::npos) {
        result.append(fileContent, prevPos, pos - prevPos);
        result.append(s2);
        prevPos = pos + s1.length();
    }
    result.append(fileContent, prevPos, std::string::npos);

    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Error: Could not create the file '" << outputFilename << "'." << "\n";
        return;
    }
    outputFile << result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout  << "Wrong number of Arguments" << "\n";
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    replaceStringInFile(filename, s1, s2);
    return 0;
}
