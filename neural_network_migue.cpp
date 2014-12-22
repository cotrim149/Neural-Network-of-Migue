#include <iostream>
#include <string>
#include <math.h>

float calculate_mean(std::string string_mean){
	//Calculating the mean array
	int i;
	float sum = 0;
	for (i = 0; i < string_mean.length(); ++i){
		sum = sum + string_mean[i];
	}
	sum = sum/string_mean.length();
	return sum;
}

float calculate_covariance(std::string string_1, std::string string_2){
	//Calculate means of strings
	float mean_1  = calculate_mean(string_1);
	float mean_2  = calculate_mean(string_2);
	int i;
	float covariance = 0;

	//Determine the minor string
	int length_min;
	if(string_1.length() > string_2.length()){
		length_min = string_2.length();
	}else if(string_1.length() < string_2.length()){
		length_min = string_1.length();
	}else {
		length_min = string_1.length();
	}

	//Calculate the covariance
	for (i = 0; i < length_min; ++i){
		covariance = covariance + (string_1[i] - mean_1)*(string_2[i] - mean_2);
	}
	return covariance;
}

//Neuron's Function of Transfer
float calculate_correlation_pearson(std::string string_1, std::string string_2){
	float standart_deviation_1 = sqrt(calculate_covariance(string_1, string_1));
	float standart_deviation_2 = sqrt(calculate_covariance(string_2, string_2));
	float correlation = calculate_covariance(string_1, string_2);
	float normalization_part = standart_deviation_1*standart_deviation_2;
	correlation = correlation/normalization_part;
	return correlation;
}

float know_neuron_migue_master(std::string name){
	std::string name_migue_master = "Afonso";
	return calculate_correlation_pearson(name, name_migue_master);
}

float know_neuron_migue(std::string name){
	std::string name_migue = "Pedro";
	return calculate_correlation_pearson(name, name_migue);
}

float know_neuron_not_migue(std::string name){
	std::string name_not_migue = "Zulmira";
	return calculate_correlation_pearson(name, name_not_migue);
}

std::string get_migue_classification(std::string name){
	std::string migue_classification;
	float index_not_migue = know_neuron_not_migue(name);
	float index_migue = know_neuron_migue(name);
	float index_migue_master = know_neuron_migue_master(name);
	if(index_not_migue > index_migue && index_not_migue > index_migue_master){
		migue_classification = "nao eh migue.";
	}else if(index_migue > index_not_migue && index_migue > index_migue_master){
		migue_classification = "eh um migue.";
	}else{
		migue_classification = "eh um migue master.";
	}
	return migue_classification;
}

int main(int argc, char** argv) {
	std::string name;
	std::cout <<  "\n\n\nDigite o nome da pessoa para eu falar da procedencia de miguelagem dela: " << std::endl;
	std::cin >> name;
	std::cout <<  "\n\nResultado: essa pessoa " + get_migue_classification(name) << std::endl;
	return 0;
}
