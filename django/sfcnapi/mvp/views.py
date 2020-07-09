from django.shortcuts import render
from rest_framework import status
from rest_framework.decorators import api_view
from rest_framework.response import Response
from math import sqrt

# Create your views here.
@api_view(["GET", "POST"])
def fxn_sqrt(request):
    """
    Take the square root of the provided input and return it
    :param request:
    :return:
    """

    if request.method in ["GET", "POST"]:
        params = request.query_params
        data = dict()
        try:
            data["value"] = sqrt(float(params["value"]))
        except ValueError:
            data["value"] = -1
        return Response(data=data)
