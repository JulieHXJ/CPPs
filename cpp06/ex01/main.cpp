/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:51:44 by junjun            #+#    #+#             */
/*   Updated: 2025/08/23 15:04:12 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data data;
	data.id = 42;
	data.name = "Example";
	data.value = 3.14;
	// Data* ptr = &data; //for checking address
	
	std::cout << "Original Data - id: " << data.id << ", name: " << data.name << ", value: " << data.value << "\n";
	std::cout << "Original Data address: " << &data << "\n";

	//serialize
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw uintptr_t: " << raw << "\n";

	//deserialize
	Data* newData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data - id: " << newData->id << ", name: " << newData->name << ", value: " << newData->value << "\n";
	std::cout << "Deserialized Data address: " << newData << "\n";


	//modify newData to see if it affects original data
	newData->id = 100;
    std::cout << "data.id after change newData: " << data.id << std::endl;

	return 0;
	
}