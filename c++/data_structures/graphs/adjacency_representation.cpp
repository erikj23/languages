#include <list>
#include <iostream>
#include <string>

void reverse(std::list<std::string> source[], std::list<std::string> destination[], std::size_t size)
{ 
  for(std::size_t i = 0; i < size; ++i) 
    for(std::list<std::string>::iterator it = source[i].begin(); it != source[i].end(); ++it)
      destination[i].push_front(*it);
}

int main() 
{
  std::size_t size = 6;
  std::list<std::string> graph[size];
    graph[0].push_back("A"); graph[0].push_back("B");
    graph[1].push_back("B"); graph[1].push_back("C"); graph[1].push_back("E");
    graph[2].push_back("C"); graph[2].push_back("A");
    graph[3].push_back("D"); graph[3].push_back("E");
    graph[4].push_back("E"); graph[4].push_back("F");
    graph[5].push_back("F"); graph[5].push_back("D");
  std::list<std::string> copy[size];
  
  reverse(graph, copy, size);

  for(std::size_t i = 0; i < size; ++i) 
  {
    for(std::list<std::string>::iterator it = copy[i].begin(); it != copy[i].end(); ++it) 
    {
      std::cout << *it;
    }
    std::cout << std::endl;
  }
  return 0;
}