#pragma once

#include <drogon/HttpController.h>
#include "../models/Job.h"

using namespace drogon;
using namespace drogon_model::org_chart;

class JobsController:public drogon::HttpController<JobsController>
{
  public:
    METHOD_LIST_BEGIN
			ADD_METHOD_TO(JobsController::createOne, "/jobs", Post);
		  ADD_METHOD_TO(JobsController::get,"/jobs", Get);
		  ADD_METHOD_TO(JobsController::getOne,"/jobs/{1}", Get);
      ADD_METHOD_TO(JobsController::updateOne,"/jobs/{1}", Put);
      ADD_METHOD_TO(JobsController::deleteOne,"/jobs/{1}", Delete);
      ADD_METHOD_TO(JobsController::getJobPersons,"/jobs/{1}/persons", Get);
    METHOD_LIST_END

    void createOne(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback, Job &&pJob) const;
    void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) const;
    void getOne(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int pJobId) const;
		void updateOne(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback, int pJobId, Job &&pJob) const;
    void deleteOne(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback, int pJobId) const;
    void getJobPersons(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback, int jobId) const;
};
