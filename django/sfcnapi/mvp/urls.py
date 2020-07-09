from django.urls import path

from . import views

urlpatterns = [
    path('sqrt', views.fxn_sqrt, name='sqrt-example')
]
