#include "MetricLogger.h"

// constructor
MetricLogger::MetricLogger()
{
}

// adds a metric
void MetricLogger::AddMetric(std::string key, float value, bool replaceValue)
{
	// key exists
	if (metrics.find(key) != metrics.end() && replaceValue)
	{
		metrics[key] = value;
	}
	else // key doesn't exist
	{
		metrics[key] = value;
	}
}

// inserts a metric
// void MetricLogger::InsertMetric(std::string key, int index, float value)
// {
// 	if (index > metrics.size())
// 	{
// 		metrics[key] = value;
// 	}
// 	else
// 	{
// 		metrics.insert(std::make_pair<std::string, float>(key, value));
// 	}
// }

// edits a metric
void MetricLogger::EditMetric(std::string key, float newValue)
{
	if (metrics.find(key) != metrics.end())
		metrics.at(key) = newValue;
}

// removes metric
void MetricLogger::RemoveMetric(std::string key)
{
	// if the key exists, remove it.
	if (metrics.find(key) != metrics.end())
	{
		metrics.erase(key);
	}
}

// returns the metric at the provided index.
float MetricLogger::GetMetric(std::string key)
{
	if (metrics.find(key) != metrics.end())
		return metrics[key];
	else
		return 0.0F;
}

// gets the amount of metrics
int MetricLogger::GetMetricCount() const
{
	return metrics.size();
}

// checks to see if the metric logger is empty
bool MetricLogger::IsEmpty()
{
	return metrics.empty();
}

// clears out the metrics
void MetricLogger::Clear()
{
	metrics.clear();
}
