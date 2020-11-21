#include "Wrapper.h"

MetricsLogger logger;

// adds a metric
PLUGIN_API void AddMetric(const char* key, int length, float value)
{
	logger.AddMetric(std::string(key), value);
}

// adds a metric
// PLUGIN_API void AddMetric(char* key, int length, float value, int replaceValue)
// {
// 	// any value other than 0 will convert to a 'true' bool. A zero makes it false.
// 	logger.AddMetric(std::string(key), value, (bool)replaceValue);
// }

// edits a metric
void EditMetric(const char* key, int length, float newValue)
{
	logger.AddMetric(std::string(key), newValue);
}

// removes a metric
PLUGIN_API void RemoveMetric(const char* key, int length)
{
	logger.RemoveMetric(key);
}

// gets the metric
PLUGIN_API float GetMetric(const char* key, int length)
{
	return logger.GetMetric(std::string(key));
}

// gets the metric count
PLUGIN_API int GetMetricCount()
{
	return logger.GetMetricCount();
}

// checks to see if the logger is empty.
PLUGIN_API int IsEmpty()
{
	return (int)logger.IsEmpty();
}

// clears out metrics
PLUGIN_API void Clear()
{
	return logger.Clear();
}

// sets the file
PLUGIN_API void SetFile(const char* file, int length)
{
	logger.SetFile(std::string(file));
}

// gets the file
// PLUGIN_API void GetFile(char* file, int length)
// {
// 	memcpy(file, logger.GetFile().c_str(), sizeof(char) * length);
// }

// return the file
PLUGIN_API const char* GetFile()
{
	return logger.GetFile().c_str();
}

// gets the length of the file name.
PLUGIN_API int GetFileNameLength()
{
	return logger.GetFileNameLength();
}

// imports metrics from set file
PLUGIN_API int ImportMetrics()
{
	return logger.ImportMetrics();
}

// exports metrics
PLUGIN_API int ExportMetrics()
{
	return logger.ExportMetrics();
}

// PLUGIN_API const char* Func()
// {
// 	return nullptr;
// }
