#pragma once
#include "PluginSettings.h"
#include <string>
#include <vector>
#include <unordered_map>

// class
class PLUGIN_API MetricsLogger
{
	
public:
	// constructor
	MetricsLogger();

	// adds a metric. If a metric already exists, the value is overrided.
	void AddMetric(std::string key, float value);

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

	// returns and returns an array of list keys.
	// this is not saved
	std::string* GenerateKeyArray() const;

	// generates an array of values in the list.
	// this is not saved
	float* GenerateValueArray() const;

	// sets the file this metric logger will save to.
	void SetFile(std::string file);

	// gets the file name, which includes its path.
	std::string GetFile() const;

	// imports metrics from set file
	// any underscore in key names is replaced with a space
	bool ImportMetrics();
	
	// imports metrics from the provided file. Saves file if successful import.
	bool ImportMetrics(std::string file);

	// exports metrics to set file.
	// if the key has a space in it, its replaced with an underscore.
	// the file is still made if there are no metrics.
	bool ExportMetrics();

	// exports metrics to a file (saves provided file)
	bool ExportMetrics(std::string file);


private:
	std::unordered_map<std::string, float> metrics;

	// the file name for the mtrics logger
	std::string file = "";

protected:

};