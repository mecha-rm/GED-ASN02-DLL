#pragma once
#include "PluginSettings.h"
#include <string>
#include <vector>
#include <unordered_map>

// class
class PLUGIN_API MetricLogger
{
	
public:
	// constructor
	MetricLogger();	

	// adds a metric
	// if that metric already exists, then its added to its bucket
	void AddMetric(std::string key, float value, bool replaceValue);

	// inserts a metric
	// if 'replaceValue' is true, then the value here is replaced
	// void InsertMetric(std::string key, int index, float value);

	// edits a metric
	void EditMetric(std::string key, float newValue);

	// removes a metric based on its key.
	void RemoveMetric(std::string key);

	// returns a metric based on the provided key
	float GetMetric(std::string key);

	// returns the metric count
	int GetMetricCount() const;

	// checks to see if the metrics list is empty
	bool IsEmpty();

	// clears out all metrics
	void Clear();

	// void LoadFromFile(std::string fileName);

	// void SaveToFile(std::string fileName);

	// gets the file and its path (if applicable)
	// std::string GetFile();

private:
	std::unordered_map<std::string, float> metrics;

protected:

};